#include "draw.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <math.h>
#include <cmath> 

using namespace std;
using namespace cs225;

PNG * Draw::open() {
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
    unsigned int width = image->width();
    unsigned int height = image->height();

    // change the coordinate to correspond to the point on map
    unsigned int x_1 = ((width / 2) + (longitude_1 * width) / 360);
    unsigned int y_1 = ((height / 2) - (latitude_1 * height) / 180);
    unsigned int x_2 = ((width / 2) + (longitude_2 * width) / 360);
    unsigned int y_2 = ((height / 2) - (latitude_2 * height) / 180);

    unsigned int delta_y = float(max(y_2, y_1) - min(y_2, y_1));
    unsigned int delta_x = float(max(x_2, x_1) - min(x_2, x_1));  
    cout << delta_x << " " << delta_y << " " << endl;
    // if (delta_x > width / 2) {
    //     drawlineHelper_2(image, x_1, y_1, x_2, y_2);
    //     return;
    // }

    float ratio = float(delta_y) / float(delta_x);

    if (delta_y > delta_x) {
        drawlineHelper(image, x_1, y_1, x_2, y_2, ratio);
        cout << "here_helper" << endl;
        return;
    }
    
    cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << " " << ratio << " " << endl;
    //make sure y_1 is the airport with lower latitude(larger y coordinate)
    if (y_1 < y_2) {        
        swap(y_1, y_2);
        swap(x_1, x_2);
    }
    unsigned int curr_y = y_1;
    float error = 0;
    int step_x = 1;
    if (x_1 > x_2) {
        step_x = -1;
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
    }
    cout << "here" << endl;
    return;
}

void Draw::drawlineHelper(PNG * image, unsigned int x_1, unsigned int y_1, unsigned int x_2, unsigned int y_2, float ratio) {
    ratio = 1/ratio; 
    if (x_1 > x_2) {        
        swap(y_1, y_2);
        swap(x_1, x_2);
    }
    unsigned int curr_x = x_1;
    float error = 0;
    int step_y = 1;
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
            curr_x++;
            error -= 1;
        }
        y_1 += step_y;
    }
    return;
}

void drawlineHelper_2(PNG * image, unsigned int x_1, unsigned int y_1, unsigned int x_2, unsigned int y_2) {
    return;
}

void drawmap(string & routefile, string & airportfile, Graph::Vertex start, Graph::Vertex stop) {
    return;
}
