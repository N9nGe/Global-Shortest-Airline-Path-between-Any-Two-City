/**
 * This is the functions.h file which is used to inplement all functions we used in this final project
 * like BFS, Dijkstra's Algorithm and so forth.
 */
#pragma once
#include "graph.h"
#include <string>
#include <vector>

using namespace std;

class Functions {
    public:
/**
 * default constructor
 */
        Functions() { };
        vector<vector<string>> readRoute(const string & filename);
    private:
};