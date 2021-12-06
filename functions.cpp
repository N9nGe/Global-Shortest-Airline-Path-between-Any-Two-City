#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<Graph::Vertex> Functions::BFS(Graph g) {
    Graph::Vertex start = g.getFirstVertex();
    // queue for BFS
    queue<Graph::Vertex> q;
    q.push(start);
    // // count all visited vertices
    // int count = 0;
    // use a map to keep tack of visited vertex. Default initialization is unvisited, false.
    map<string, bool> visited;
    // initialize the start vertex as visited, true.
    visited[start.getVertexId()] = true;
    // vector to store the BFS path
    vector<Graph::Vertex> result;
    while(!q.empty()) {
        // take the first element
        Graph::Vertex curr = q.front();
        q.pop();
        // store path
        result.push_back(curr);
        // count++;
        // find unvisited adjacent vertex and update
        for (Graph::Vertex& v: g.getAdjacentVertex(curr)) {
            if (!visited[v.getVertexId()]) {
                q.push(v);
                visited[v.getVertexId()] = true;
            }
        }
    }
    return result;
}

map<Graph::Vertex, Graph::Vertex> Functions::Dijkstra(Graph g) {
    Graph::Vertex start = g.getFirstVertex();
    // priority queue for Dijkstra
    typedef pair<int, Graph::Vertex> iPair;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    // record each vertex's distance and path
    map<Graph::Vertex, int> dist;
    map<Graph::Vertex, Graph::Vertex> path;
    map<Graph::Vertex, bool> visited;
    // buggy code:
    // for (Graph::Vertex& v: g.getAllVertices()) {
    //     dist[v] = __INT_MAX__;
    //     path[v] = Graph::Vertex();
    // }
    // // initialize the start point
    // pq.push(iPair(0, start));
    // dist[start] = 0;
    // visited[start] = true;
    // while(!pq.empty()) {
    //     // take the first element
    //     Graph::Vertex curr = pq.top().second;
    //     pq.pop();
    //     // visited vertex
    //     visited[curr] = true;
    //     for(Graph::Vertex& v: g.getAdjacentVertex(curr)) {
    //         if (!visited[v]) {
    //             Graph::Edge edge = g.getEdge(curr, v);
    //             double weight = edge.getDistance();
    //             // update distance
    //             if (weight + dist[curr] < dist[v]) {
    //                 dist[v] = weight + dist[curr];
    //                 path[v] = curr;
    //                 pq.push(iPair(dist[v], v));
    //             }
    //         }
    //     }
    // }
    return path;
}