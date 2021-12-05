#include "draw.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include <math.h> 

using namespace std;
using namespace cs225;
    PNG * open() {
    PNG * image = new PNG();
    image->readFromFile("map.png");
    return image;
}

void output(PNG * image) {
    image->writeToFile("output_map.png");
    delete image;
}

void drawpoint(PNG * image, double latitude, double longitude) {
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
            pixel.h =240;
            pixel.s = 1;
            pixel.l = 0.5;
            pixel.a = 1;
        }
    }
}

void drawline(PNG * image, double latitude_1, double longitude_1, double latitude_2, double longitude_2) {
    
}
