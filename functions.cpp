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
// vector<Graph::Vertex> Functions::BFS(Graph g, Graph::Vertex start) {
//     // queue for BFS
//     queue<Graph::Vertex> q;
//     start = g.getFirstVertex();
//     q.push(start);
//     // use a map to keep tack of visited vertex. Default initialization is unvisited, false.
//     map<string, bool> visited;
//     // initialize the start vertex as visited, true.
//     visited[start.getVertexId()] = true;
//     // vector to store the BFS path
//     vector<Graph::Vertex> result;
//     while(!q.empty()) {
//         // dequene the first element
//         Graph::Vertex curr = q.front();
//         q.pop();
//         // store path
//         result.push_back(curr);
//         // find unvisited adjacent vertex and update
//         for (Graph::Vertex& v: g.getAdjacentVertex(curr)) {
//             if (!visited[v.getVertexId()]) {
//                 q.push(v);
//                 visited[v.getVertexId()] = true;
//             }
//         }
//     }
//     return result;
// }
