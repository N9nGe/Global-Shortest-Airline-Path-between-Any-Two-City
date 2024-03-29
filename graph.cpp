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
        string vertexId = (*it).first;
        string lat = (*it).second[0];
        string longi = (*it).second[1];
        //skip incorrect dataset
        try {
            double latitudeDouble = stod(lat);
            double longitudeDouble = stod(longi);
            Vertex vertex(vertexId, latitudeDouble, longitudeDouble);
            insertVertex(vertex);
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
        Vertex v(sourceId);
        adjacencyList[sourceId].push_back(edge);
    }
}

Graph::Vertex Graph::getFirstVertex() {
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        if ((*it).second.size() >= 1) {
            return getVertex((*it).first);
        }
    }
    Vertex v;
    return v;
}

Graph::Vertex Graph::getVertex(string vertexId) {
    if (vertices.find(vertexId) != vertices.end()) {
        return vertices[vertexId];
    }
    Vertex v;
    return v;
}

vector<Graph::Vertex> Graph::getAllVertices() {
    vector<Graph::Vertex> result;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        if ((*it).second.size() >= 1) {
            result.push_back(getVertex((*it).first));
        }
    }
    return result;
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
        adjacencyList[id] = l;
    }
}

void Graph::removeVertex(Vertex v) {
    string id = v.vertex_id;
    vertices.erase(id);
    adjacencyList.erase(id);
}

Graph::Edge Graph::getEdge(Graph::Vertex source, Graph::Vertex destination) {
    if (adjacencyList.find(source.vertex_id) == adjacencyList.end() || adjacencyList.find(destination.vertex_id) == adjacencyList.end()) {
        Edge e;
        return e;
    }
    auto it = adjacencyList.find(source.vertex_id);
    for (auto lit = (*it).second.begin(); lit != (*it).second.end(); ++lit) {
        if ((*lit).destination_id == destination.vertex_id) {
            return (*lit);
        }
    }
    Edge e;
    return e;
}

vector<Graph::Edge> Graph::getIncidentEdge(Graph::Vertex v) {
    if (adjacencyList.find(v.vertex_id) == adjacencyList.end()) {
        vector<Edge> vec;
        return vec;
    }
    vector<Edge> edges;
    auto it = adjacencyList.find(v.vertex_id);
    for (auto lit = (*it).second.begin(); lit != (*it).second.end(); ++lit) {
        edges.push_back(*lit);
    }
    return edges;
}

void Graph::insertEdge(Graph::Edge e) {
    if (adjacencyList.find(e.source_id) == adjacencyList.end() || adjacencyList.find(e.destination_id) == adjacencyList.end()) {
        return;
    }
    adjacencyList[e.source_id].push_front(e);
}

void Graph::removeEdge(Graph::Edge e) {
    if (adjacencyList.find(e.source_id) == adjacencyList.end() || adjacencyList.find(e.destination_id) == adjacencyList.end()) {
        return;
    }
    for (auto it = adjacencyList[e.source_id].begin(); it != adjacencyList[e.source_id].end(); ++it) {
        if ((*it).destination_id == e.destination_id) {
            adjacencyList[e.source_id].erase(it);
        }
    }
}

bool Graph::routeToVertex(Graph::Vertex v) {
    bool connected = false;
    for (auto it = route.begin(); it != route.end(); ++it) {
        string sourceId = (*it)[3];
        string destId = (*it)[5];
        if (destId == v.vertex_id) {
            connected = true;
        }
    }
    return connected;     
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