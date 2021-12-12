#include "draw.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <math.h>
#include <cmath> 

using namespace std;
using namespace cs225;

PNG * Draw::open() {
    //Initilize image with the original world map PNG
    PNG * image = new PNG();
    image->readFromFile("map.png");
    return image;
}

void Draw::output(PNG * image) {
    image->writeToFile("output_map.png");
    delete image;
}

void Draw::drawpoint(PNG * image, double latitude, double longitude) {
    unsigned int width = image->width();
    unsigned int height = image->height();

    // change the coordinate to correspond to the point on map
    unsigned int x = ((width / 2) + (longitude * width) / 360);
    unsigned int y = ((height / 2) - (latitude * height) / 180);
    
    // make the point bigger and more precise.
    for (unsigned int i = x - 2; i <= x + 2; i++) {
        for (unsigned int j = y - 2; j <= y + 2; j++) {
            HSLAPixel & pixel = image->getPixel(i , j);
            // using blue point
            pixel.h = 240;
            pixel.s = 1;
            pixel.l = 0.5;
            pixel.a = 1;
        }
    }
}


void Draw::drawline(PNG * image, double latitude_1, double longitude_1, double latitude_2, double longitude_2) {
    int width = image->width();
    int height = image->height();

    // change the coordinate to correspond to the point on map
    int x_1 = ((width / 2) + (longitude_1 * width) / 360);
    int y_1 = ((height / 2) - (latitude_1 * height) / 180);
    int x_2 = ((width / 2) + (longitude_2 * width) / 360);
    int y_2 = ((height / 2) - (latitude_2 * height) / 180);

    int delta_y = float(max(y_2, y_1) - min(y_2, y_1));
    int delta_x = float(max(x_2, x_1) - min(x_2, x_1));  

    float ratio = float(delta_y) / float(delta_x);
    int step_x = 1;
    int step = 1;
    
    //make sure y_1 is the airport with lower latitude(larger y coordinate)
    if (y_1 < y_2) {        
        swap(y_1, y_2);
        swap(x_1, x_2);
    }

    //make necessary changes when the airline should go in another direction  
    if (delta_x > width / 2) {
        step_x = -1;
        step = -1;
        ratio = float(delta_y) / (width - float(delta_x));
    }

    //write another case when delta_y is greater than delta_x
    if (ratio > 1) {
        drawlineHelper(image, x_1, y_1, x_2, y_2, 1/ratio, step);
        return;
    }

    int curr_y = y_1;
    float error = 0;
    if (x_1 > x_2) {
        step_x = -step_x;
    }
    while (x_1 != x_2) {
        HSLAPixel & pixel = image->getPixel(x_1, curr_y);
        // using red point
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
        error += ratio;
        if (error >= 0.5) {
            curr_y--;
            error -= 1;
        }
        x_1 += step_x;
        if (x_1 >= width) {
            x_1 = 0;
        }
        if (x_1 < 0) {
            x_1 = width-1;
        }
    }
    return;
}

void Draw::drawlineHelper(PNG * image, int x_1, int y_1, int x_2, int y_2, float ratio, int step) {
    int width = int(image->width());
    int step_y = 1;
    
    if (x_1 > x_2) {        
        swap(y_1, y_2);
        swap(x_1, x_2);
    }
    int curr_x = x_1;
    float error = 0;
    if (y_1 > y_2) {
        step_y = -1;
    } 
    while (y_1 != y_2) {
        HSLAPixel & pixel = image->getPixel(curr_x, y_1);
        // using red point
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
        error += ratio;
        if (error >= 0.5) {
            curr_x+=step;
            if (curr_x >= width) {
            curr_x = 0;
            }
            if (curr_x < 0) {
                curr_x = width-1;
            }
            error -= 1;
        }
        y_1 += step_y;
    }
    return;
}

void Draw::drawmap(const string & routefile, const string & airportfile, Graph::Vertex start, Graph::Vertex stop) {
    //initialize variables
    cs225::PNG * image = open();
    Graph g(routefile, airportfile);
    Functions temp;
    map<string, string> path = temp.Dijkstra(g, start, stop);
    vector<string> points;
    string curr = stop.vertex_id;
    points.push_back(curr);
    //iterate through output of the Dijkstra algorithm
    map<string, string>::iterator lookup = path.find(curr);
    while (lookup->second != "") {
        points.push_back((*lookup).second);
        lookup = path.find((*lookup).second);
    }
    //draw airports and routes on the map
    for (size_t i = 0; i < points.size() - 1; i++) {
        Graph::Vertex first = g.getVertex(points[i]);
        Graph::Vertex second = g.getVertex(points[i+1]);
        double x_1 = first.latitude;
        double y_1 = first.longitude;
        double x_2 = second.latitude;
        double y_2 = second.longitude;
        drawpoint(image, x_1, y_1);
        drawpoint(image, x_2, y_2);
        drawline(image, x_1, y_1, x_2, y_2);
    }
    //print shortest path information
    cout << "The shortest path is shown below: " << endl;
    for (size_t i = points.size() - 1; i >= 0 && i < points.size(); i--) {
        if (i > 0) {
            cout << g.getVertex(points[i]).vertex_id << " -> ";
            continue;
        }
            cout << g.getVertex(points[i]).vertex_id << endl;
    }
    output(image);
    return;
}
