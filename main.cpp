#include <iostream>
#include "cs225/PNG.h"
#include "graph.h"
#include "draw.h"
#include "functions.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string airportsDir = "data/airports.dat";
    string routesDir = "data/routes.dat";
    //Create a Graph object
    Graph g(routesDir, airportsDir);
    //BFS start airport id
    string bfsStartId = "1555";
    Graph::Vertex bfsStartTemp = g.getVertex(bfsStartId);
    Graph::Vertex bfsStart(bfsStartId, bfsStartTemp.latitude, bfsStartTemp.longitude);
    Functions func;

    //BFS and draw traversed edges and vertices on a map
    vector<Graph::Vertex> list = func.BFS(g, bfsStart);
    cout << "BFS traversal result:"<<endl;
    cout << "first visited: " + (*(list.begin())).vertex_id <<endl;
    cout << "last visited: " + (*(list.end() - 1)).vertex_id <<endl;
    cout << "BFS size is " << list.size() << endl;

    Draw drawBFS;
    PNG * all_airlines = drawBFS.open();
    for (size_t i = 0; i < list.size() - 1; i++) {
        Graph::Vertex first = list[i];
        Graph::Vertex second = list[i+1];
        double x_1 = first.latitude;
        double y_1 = first.longitude;
        double x_2 = second.latitude;
        double y_2 = second.longitude;
        drawBFS.drawpoint(all_airlines, x_1, y_1);
        drawBFS.drawpoint(all_airlines, x_2, y_2);
        drawBFS.drawline(all_airlines, x_1, y_1, x_2, y_2);
    }
    
    all_airlines->writeToFile("all_airlines.png");

    //Find the shortest path between two airports and draw it on a map
    Draw drawPath;
    PNG * shortestPath = drawPath.open();
    //id of the start airport, change this if you want to use other start airport
    string startId = "2188";
    //id of the end airport, change this if you want to use other start airport
    string endId = "3830";
    Graph::Vertex startTemp = g.getVertex(startId);
    Graph::Vertex endTemp = g.getVertex(endId);
    Graph::Vertex start(startId, startTemp.latitude, startTemp.longitude);
    Graph::Vertex end(endId, endTemp.latitude, endTemp.longitude);
    if (g.getAdjacentVertex(start).size() < 1 || g.getAdjacentVertex(end).size() < 1) {
        cout<<"invalid airport id, please choose airports that have route to other airports."<<endl;
        return 0;
    }
    drawPath.drawmap(routesDir, airportsDir, start, end);
    return 0;
}
