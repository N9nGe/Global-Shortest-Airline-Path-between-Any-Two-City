#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// this is a draft of BFS implementation, because for now graph implementation is not complete
// possible missing functions in graph.cpp are vertex constructor, vertex::getId(), and vertex::getAdj()
//vector<vertex> Functions::BFS(Graph g, vertex start) {
    // queue for BFS
    //queue<vertex> q;
    /*q.push(start);
    // use a map to keep tack of visited vertex. Default initialization is unvisited, false.
    map<string, bool> visited;
    // initialize the start vertex as visited, true.
    visited[start.getId()] = true;
    // vector to store the BFS path
    vector<vertex> result;
    while(!q.empty()) {
        // dequene the first element
        vertex curr = q.front();
        q.pop();
        // store path
        result.push_back(curr);
        // find unvisited adjacent vertex and update
        for (vertex& v: curr.getAdj()) {
            if (!visited[v.getId()]) {
                q.push(v);
                visited[v.getId()] = true;
            }
        }
    }*/
    //return result;
//}
