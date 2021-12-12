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
         * @return a vector in the BFS order
         */
        vector<Graph::Vertex> BFS(Graph g);

        /** 
         * BFS traversal of a given graph and given strat vertex
         * @param g the graph to traverse
         * @param start start vertex
         * @return a vector in the BFS order
         */
        vector<Graph::Vertex> BFS(Graph g, Graph::Vertex strat);

        /** 
         * Dijkstra to find the shortest path
         * @param g the graph to traverse
         * @param start start vertex
         * @param end destination vertex
         * @return former vertex of the destination
         */
        map<string, string> Dijkstra(Graph g, Graph::Vertex start, Graph::Vertex end);
    private:
};