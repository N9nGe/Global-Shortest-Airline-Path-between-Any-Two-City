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
    Graph g("route_testcase_1.dat", "Airport_testcase_1.dat"); //try create a Graph object
    //Graph g2;
    //cout << "Add your own tests here! Modify main.cpp" << endl;
    string id = "3364";
    //cout<<g.getVertex(id).vertex_id;
    //cout<<" ";
    Graph::Vertex v(id);
    Graph::Edge e("3364", "3366", 1046.256371);
    //g.insertVertex(v);
    //cout<<g.getFirstVertex().vertexToString();
    vector<Graph::Vertex> vs = g.getAdjacentVertex(v);
    vector<Graph::Edge> es = g.getIncidentEdge(v);
    cout<<id;
    cout<<": ";
    for (auto it = es.begin(); it != es.end(); ++it) {
        //cout<<(*it).vertexToString();
        cout<<(*it).edgeToString();
        cout<<" -> ";
    }
    cout<<""<<endl;
    g.removeEdge(e);
    es = g.getIncidentEdge(v);
    cout<<id;
    cout<<": ";
    for (auto it = es.begin(); it != es.end(); ++it) {
        //cout<<(*it).vertexToString();
        cout<<(*it).edgeToString();
        cout<<" -> ";
    }
    cout<<""<<endl;
    g.removeEdge(e);
    g.insertEdge(e);
    es = g.getIncidentEdge(v);
    cout<<id;
    cout<<": ";
    for (auto it = es.begin(); it != es.end(); ++it) {
        //cout<<(*it).vertexToString();
        cout<<(*it).edgeToString();
        cout<<" -> ";
    }
    return 0;
}
