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
// default constructor
        Functions() { };
        /** 
         * BFS traversal of a given graph
         * @param g the graph to traverse
         * @param start start vertex
         * @return a vector in the BFS order
         */
        vector<Graph::Vertex> BFS(Graph g);
        /** 
         * Dijkstra to find the shortest path
         * @param g the graph to traverse
         * @param source start vertex
         * @param destination destination vertex
         * @return path of the shortest route
         */
        map<string, string> Dijkstra(Graph g, Graph::Vertex start, Graph::Vertex end);
        // vector<vector<string>> readRoute(const string & filename);
    private:
};