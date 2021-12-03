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
    for (auto it = airportPosition.begin(); it != airportPosition.end(); ++it) {
        /*cout<<(*it).first;
        cout<<", ";
        cout<<(*it).second[1];
        cout<<""<<endl;*/
        string vertexId = (*it).first;
        string lat = (*it).second[1];
        string longi = (*it).second[2];
        //skip incorrect dataset
        try {
            double latitudeDouble = stod(lat);
            double longitudeDouble = stod(longi);
            Vertex vertex(vertexId, latitudeDouble, longitudeDouble);
            vertices[vertexId] = vertex;
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }

    for (auto it = route.begin(); it != route.end(); ++it) {
        string sourceId = (*it)[3];
        string destId = (*it)[5];
        double sLat = vertices.find(sourceId)->second.latitude;
        double sLong = vertices.find(sourceId)->second.longitude;
        double dLat = vertices.find(destId)->second.latitude;
        double dLong = vertices.find(destId)->second.longitude;
        double edgeDistance = calculateDistance(sLat, sLong, dLat, dLong);
        Edge edge(sourceId, destId, edgeDistance);
        adjacencyList.find(sourceId)->second.push_back(edge);
        adjacencyList.find(destId)->second.push_back(edge);
    }

    /*for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        cout<<(*it).first;
        cout<<": ";
        cout<<(*it).second.vertex_id;
        cout<<", ";
        cout<<(*it).second.latitude;
        cout<<", ";
        cout<<(*it).second.longitude;
        cout<<""<<endl;
    }*/

    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        cout<<(*it).first;
        cout<<": ";
        for (auto lit = (*it).second.begin(); lit != (*it).second.end(); ++lit) {
            cout<<(*lit).source_id;
            cout<<", ";
            cout<<(*lit).destination_id;
            cout<<", ";
            cout<<(*lit).distance;
            cout<<" -> ";
        }
        cout<<""<<endl;
    }
}

double Graph::calculateDistance(double sourceLat, double sourceLong, double destLat, double destLong) {
    return -1;
}