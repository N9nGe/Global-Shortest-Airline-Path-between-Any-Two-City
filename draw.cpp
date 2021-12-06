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
    if (delta_y > delta_x) {
        drawlineHelper(image, x_1, y_1, x_2, y_2);
        cout << "here_helper" << endl;
        return;
    }

    unsigned int ratio = round(float(delta_x) / float(delta_y));
    //unsigned int ratio = round(realRatio);
    float reminder = float(delta_x) / float(delta_y) - ratio;
    
    cout << x_1 << " " << y_1 << " " << x_2 << " " << y_2 << " " << ratio << " " << reminder << endl;
    //make sure y_1 is the airport with higher latitude(smaller y coordinate)
    if (y_1 > y_2) {        
        swap(y_1, y_2);
        swap(x_1, x_2);
    }
    unsigned int curr_x = x_1;
    float count = 0;
    if (x_2 < x_1) {
        for (unsigned int j = y_1; j < y_2; j++) {
            for (unsigned int i = curr_x; i >= curr_x - ratio && i >= x_2; i--) {
                HSLAPixel & pixel = image->getPixel(i, j);
                // using red point
                pixel.h = 0;
                pixel.s = 1;
                pixel.l = 0.5;
                pixel.a = 1;
                count += reminder;
                if (count >= 1) {
                    i--;
                    //j--;
                    count -= 1;
                }
            }
            curr_x -= ratio;
            //ratio = round(float(x_2 - curr_x) / float(y_2 - j));
            //reminder = float(x_2 - curr_x) / float(y_2 - j) - ratio;
        }
    } else {
        for (unsigned int j = y_1; j < y_2; j++) {
            for (unsigned int i = curr_x; i <= curr_x + ratio && i <= x_2; i++) {
                HSLAPixel & pixel = image->getPixel(i, j);
                // using red point
                pixel.h = 0;
                pixel.s = 1;
                pixel.l = 0.5;
                pixel.a = 1;
                count += reminder;
                if (count >= 1) {
                    i--;
                    j--;
                    count -= 1;
                }
            }
            curr_x += ratio;
            //ratio = round(float(x_2 - curr_x) / float(y_2 - j));
        }
    }
    cout << "here" << endl;
    return;
}

void Draw::drawlineHelper(PNG * image, unsigned int x_1, unsigned int y_1, unsigned int x_2, unsigned int y_2) {
    unsigned int delta_y = float(max(y_2, y_1) - min(y_2, y_1));
    unsigned int delta_x = float(max(x_2, x_1) - min(x_2, x_1));  
    unsigned int ratio = round(float(delta_y) / float(delta_x));
    //make sure y_1 is the airport with higher latitude(smaller y coordinate)
    if (x_1 > x_2) {        
        swap(y_1, y_2);
        swap(x_1, x_2);
    }
    unsigned int curr_y = y_1;
    if (y_2 < y_1) {
        for (unsigned int i = x_1; i < x_2; i++) {
            for (unsigned int j = curr_y; j >= curr_y - ratio && j >= y_2; j--) {
                HSLAPixel & pixel = image->getPixel(i, j);
                // using red point
                pixel.h = 0;
                pixel.s = 1;
                pixel.l = 0.5;
                pixel.a = 1;
            }
            curr_y -= ratio;
        }
    } else {
        for (unsigned int i = x_1; i < x_2; i++) {
            for (unsigned int j = curr_y; j <= curr_y + ratio && j <= y_2; j++) {
                HSLAPixel & pixel = image->getPixel(i, j);
                // using red point
                pixel.h = 0;
                pixel.s = 1;
                pixel.l = 0.5;
                pixel.a = 1;
            }
            curr_y += ratio;
        }
    }
    return;
}

void drawlineHelper_2(PNG * image, unsigned int x_1, unsigned int y_1, unsigned int x_2, unsigned int y_2) {
    return;
}

void drawmap(string & routefile, string & airportfile, Graph::Vertex start, Graph::Vertex stop) {
    return;
}
