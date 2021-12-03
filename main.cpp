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
    // Write your own main here
    Graph g("data/routes.dat", "data/airports.dat"); //try create a Graph object
    //cout << "Add your own tests here! Modify main.cpp" << endl;
    string id = "507";
    Graph::Vertex v(id);
    vector<Graph::Vertex> vs = g.getAdjacentVertex(v);
    cout<<id;
    cout<<": ";
    for (auto it = vs.begin(); it != vs.end(); ++it) {
        cout<<(*it).vertex_id;
        cout<<" -> ";
    }
    return 0;
}
