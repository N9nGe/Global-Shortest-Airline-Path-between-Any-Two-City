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
        PNG * open();
        void drawpoint(PNG * image, double latitude, double longitude);
        void drawline(PNG * image, double latitude_1, double longitude_1, double latitude_2, double longitude_2);
        void drawmap(string & routefile, string & airportfile, Graph::Vertex start, Graph::Vertex stop);
        void output(PNG * image);
};