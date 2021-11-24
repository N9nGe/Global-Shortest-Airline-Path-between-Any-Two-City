/**
 * This is graph.h file which is used to construct the basic variables used for functions
 */
#pragma once

#include <vector>

using namespace std;

class Graph {
    public:
    private:
        struct Vertex {
            string vertex_id;
            double latitude;
            double longitude;
        };

        struct Edge {
            pair<string, string> edge_id;
            double distance;
        }; 
    
};