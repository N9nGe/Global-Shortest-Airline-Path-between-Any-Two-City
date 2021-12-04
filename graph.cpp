#include "graph.h"
#include <iostream>
#include <sstream>
#include <cmath>

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
            list<Edge> l;
            adjacencyList[vertexId] = l;
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }

    for (auto it = route.begin(); it != route.end(); ++it) {
        string sourceId = (*it)[3];
        string destId = (*it)[5];
        if (sourceId == "\\N" || destId == "\\N") {
            continue;
        }
        double sLat = vertices.find(sourceId)->second.latitude;
        double sLong = vertices.find(sourceId)->second.longitude;
        double dLat = vertices.find(destId)->second.latitude;
        double dLong = vertices.find(destId)->second.longitude;
        double edgeDistance = calculateDistance(sLat, sLong, dLat, dLong);
        Edge edge(sourceId, destId, edgeDistance);
        if (adjacencyList.find(sourceId) == adjacencyList.end()) {
            //cout<<sourceId<<endl;
        }
        adjacencyList[sourceId].push_back(edge);
        adjacencyList[destId].push_back(edge);
    }

    //display vertices
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

    //display adjacency list
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        if ((*it).first == "10209") {
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
}

Graph::Vertex Graph::getFirstVertex() {
    Vertex v;
    return v;
}

vector<Graph::Vertex> Graph::getAdjacentVertex(Vertex v) {
    vector<Graph::Vertex> vs;
    string id = v.vertex_id;
    if (adjacencyList.find(id) == adjacencyList.end()) {
        return vs;
    }
    auto it = adjacencyList.find(id);
    for (auto lit = it->second.begin(); lit != it->second.end(); ++lit) {
        string neighborId;
        if ((*lit).source_id != id) {
            neighborId = (*lit).source_id;
        } else {
            neighborId = (*lit).destination_id;
        }
        //cout<<neighborId;
        //cout<<" -> ";
        auto vit = vertices.find(neighborId);
        if (vit != vertices.end()) {
            vs.push_back((*vit).second);
        }
    }
    return vs;
}

void Graph::insertVertex(Vertex v) {
    string id = v.vertex_id;
    if (vertices.find(id) == vertices.end()) {
        vertices[id] = v;
        list<Graph::Edge> l;
        if (adjacencyList.find(id) == adjacencyList.end()) {
            adjacencyList[id] = l;
        }
    }
}

void Graph::removeVertex(Vertex v) {
    string id = v.vertex_id;
    vertices.erase(id);
    adjacencyList.erase(id);
}

double Graph::calculateDistance(double sourceLat, double sourceLong, double destLat, double destLong) {
    double earthRadius = 6371;
    double phiOne = sourceLat * (M_PI / 180);
    double phiTwo = destLat * (M_PI / 180);
    double deltaPhi = (destLat-sourceLat) * (M_PI / 180);
    double deltaLambda = (destLong - sourceLong) * (M_PI / 180);
    double a = (sin(deltaPhi / 2) * sin(deltaPhi / 2)) + (cos(phiOne) * cos(phiTwo) * sin(deltaLambda / 2) * sin(deltaLambda / 2));
    double distance = earthRadius * 2 * atan2(sqrt(a), sqrt(1-a));
    return distance;
}