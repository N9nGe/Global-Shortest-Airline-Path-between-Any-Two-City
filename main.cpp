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
    
    //test draw functions 
    Draw draw;
    // PNG * graph = draw.open();
    // vector<Graph::Vertex> list = g.getAllVertices();
    // cout << endl;
    // cout << list.size() << endl;
       
    // double a = -19.4623;
    // double b = 27.5525;
    // double c = 64.9381;
    // double d = 65.4858;    

    // draw.drawpoint(graph, a, b);
    // draw.drawpoint(graph, c, d);
    // draw.drawline(graph, a, b, c, d);
    // draw.output(graph);

    //test drawmap
    Graph::Vertex CTU("3395", 30.578500747680664, 103.9469985961914);
    Graph::Vertex NGO("3942", 34.8583984375, 136.80499267578125);
    draw.drawmap("route_testcase_1.dat", "Airport_testcase_1.dat", NGO, CTU);

    return 0;
}
