#include "graph.h"
#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph() { /**empty constructor*/ }

Graph::Graph(const string & routefile, const string & airportfile) {
    Read data;
    route = data.readRoute(routefile);
    airportPosition = data.readAirportPosition(airportfile);
    airportIdDictionary = data.AirportIdDictionary(airportfile);
    // int max = 0;
    // for (auto it = airportIdDictionary.begin(); it != airportIdDictionary.end(); ++it) {
    //     string id = (*it).second;
    //     stringstream toInt(id);
    //     int intId = 0;
    //     toInt >> intId;
    //     if (intId > max) {
    //         max = intId;
    //     }
    // }
    // vertices.resize(max + 1);
    // for (auto it = airportIdDictionary.begin(); it != airportIdDictionary.end(); ++it) {
    //     Vertex vertex((*it).second);
    //     string id = (*it).second;
    //     stringstream toInt(id);
    //     int index = 0;
    //     toInt >> index;
    //     vertices[index] = vertex;
    // }
    // for (auto it = vertices.begin(); it != vertices.end(); ++it) {
    //     cout<<(*it).vertex_id<<endl;
    // }

}
