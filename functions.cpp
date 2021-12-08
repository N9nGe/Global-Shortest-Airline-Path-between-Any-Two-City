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

map<string, string> Functions::Dijkstra(Graph g, Graph::Vertex start, Graph::Vertex end) {
    // priority queue for Dijkstra
    typedef pair<double, string> iPair;
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    // record each vertex's distance and path
    map<string, double> dist;
    map<string, string> path;
    map<string, bool> visited;
    // initialization
    for (Graph::Vertex& v: g.getAllVertices()) {
        dist[v.getVertexId()] = __DBL_MAX__;
        path[v.getVertexId()] = "";
    }
    // initialize the start point
    pq.push(iPair(0, start.getVertexId()));
    dist[start.getVertexId()] = 0;
    visited[start.getVertexId()] = true;
    while(pq.top().second != end.getVertexId()) {
        // take the first element
        Graph::Vertex curr = pq.top().second;
        pq.pop();
        // visited vertex
        visited[curr.getVertexId()] = true;
        // check adjacent vertices
        for(Graph::Vertex& v: g.getAdjacentVertex(curr)) {
            if (!visited[v.getVertexId()]) {
                Graph::Edge edge = g.getEdge(curr, v);
                double weight = edge.getDistance();
                // update distance if necessary
                if ((weight + dist[curr.getVertexId()]) < dist[v.getVertexId()]) {
                    dist[v.getVertexId()] = weight + dist[curr.getVertexId()];
                    path[v.getVertexId()] = curr.getVertexId();
                    pq.push(iPair(dist[v.getVertexId()], v.getVertexId()));
                }
            }
        }
    }
    return path;
}