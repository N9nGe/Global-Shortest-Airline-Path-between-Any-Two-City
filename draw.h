/**
 * This is the draw.h which will be used to draw the lines on the global map.
*/
#pragma once
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "graph.h"
#include "functions.h"
#include "read.h"
#include <string>

using namespace std;
using namespace cs225;

class Draw {
    public:
        /** 
        * Initialization of the image
        */
        PNG * open();

        /**
        * Draw a airport on the map
        * @param image the image to draw
        * @param latitude latitude of the airport
        * @param longitude longitude of the aiport
        */
        void drawpoint(PNG * image, double latitude, double longitude);

        /**
        * Draw an airline btween two airports on the map
        * @param image the image to draw
        * @param latitude_1 latitude of the source airport
        * @param longitude_1 longitude of the source aiport
        * @param latitude_2 latitude of the destination aiport
        * @param longitude_2 longitude of the destination aiport
        */
        void drawline(PNG * image, double latitude_1, double longitude_1, double latitude_2, double longitude_2);

        /**
        * Helper function of drawline to handle cases when delta_y is greater than delta_x
        * @param image the image to draw
        * @param x_1 latitude of the source airport
        * @param y_1 longitude of the source aiport 
        * @param x_2 longitude of the destination aiport
        * @param y_2 longitude of the destination aiport
        * @param ratio value of (delta_y / delta_x)
        * @param step flag that indicates whether x should increase or decrease when iterating
        */
        void drawlineHelper(PNG * image, int x_1, int y_1, int x_2, int y_2, float ratio, int step);

        /**
        * Draw the shortest airline from a souce airport to a destination airport
        * @param routefile the png file used to make image (here we always use map.png)
        * @param airportfile the dat file used to find airports
        * @param start the vertex of the source airport
        * @param stop the vertex of the destination airport
        */
        void drawmap(const string & routefile, const string & airportfile, Graph::Vertex start, Graph::Vertex stop);

        /**
        * Output the drawn image to a given PNG
        * @param image the image to output
        */
        void output(PNG * image);
};