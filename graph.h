/**
 * This is graph.h file which is used to construct the basic variables used for functions
 */
#pragma once

#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>

#include "read.h"

using namespace std;

class Graph {
    public:
        struct Vertex {
            string vertex_id;
            double latitude;
            double longitude;

            Vertex()
            : vertex_id(""), latitude(0), longitude(0)
            {/* empty*/}

            Vertex(string airportId)
            : vertex_id(airportId), latitude(0), longitude(0)
            {/* empty*/}

            /**
            * Constructor with vertex
            * @param sourceAirport - sourceAirport
            * @param destinationAirport - destinationAirport
            */
            Vertex(string airportId, double latitudeArg, double longitudeArg) {
                vertex_id = airportId;
                latitude = latitudeArg;
                longitude = longitudeArg;
            }
            
            /**
            * Get vertex_id of Vertex
            */
            string getVertexId() {
                return vertex_id;
            }

            /**
            * Get latitude of Vertex
            */
            double getLatitude() {
                return latitude;
            }

            /**
            * Get longitude of Vertex
            */
            double getLongitude() {
                return longitude;
            }

            /**
            * operator== of Vertex
            * @param other - the other vertex to compare
            */
            bool operator==(const Vertex & other) {
                if (this->vertex_id == other.vertex_id) {
                    return true;
                } else {
                    return false;
                }
            }
        };

        struct Edge {
            string source_id;
            string destination_id;
            double distance;

            /**
            * Constructor with unweighted edge
            * @param sourceAirport - sourceAirport
            * @param destinationAirport - destinationAirport
            */
            Edge(string sourceAirport, string destinationAirport)
                : source_id(sourceAirport), destination_id(destinationAirport), distance(-1)
            {/* empty*/}

            /**
            * Constructor with weighted edge
            * @param sourceAirport - sourceAirport
            * @param destinationAirport - destinationAirport
            * @param d - the distance between the two airports(the weight of the edge)
            */
             Edge(string sourceAirport, string destinationAirport, double d)
                : source_id(sourceAirport), destination_id(destinationAirport), distance(d)
            {/* empty*/}

            /**
            * Default Constructor 
            */
            Edge()
                : source_id(""), destination_id(""), distance(-1)
            {/* empty*/}

            /**
            * operator< of Edge
            * @param other - the other edge to compare
            */
            bool operator<(const Edge & other) {
                return distance < other.distance;
            }

            /**
            * operator== of Edge
            * @param other - the other edge to compare
            */
            bool operator==(const Edge & other) {
                if (this->source_id == other.source_id && this->destination_id == other.destination_id) {
                    return true;
                } else {
                    return false;
                }
            }

            /**
            * Get distance of edge(weight)
            */
            double getDistance() {
                return distance;
            }

            /**
            * Get sourseAirportId of edge
            */
            string getSource() {
                return source_id;
            }

            /**
            * Get DestinationAirportId of edge
            */
            string getDestination() {
                return destination_id;
            }
        };
        vector<vector<string>> route;
        map<string, vector<string>> airportPosition;
        map<string, string> airportIdDictionary;

        /**
        * Default Constructor 
        */
        Graph();

        /**
        * Default Constructor 
        * @param routefile - Route file
        * @param airportfile - Airport file
        */
        Graph(const string & routefile, const string & airportfile);

        /**
        * Get first vertex of graph
        */
        Vertex getFirstVertex();

        /**
        * Get first vertex of graph
        */
        vector<Vertex> getAdjacentVertex(Vertex v);

        /**
        * Insert Vertex
        * @param v - the vertex need to insert
        */
        void insertVertex(Vertex v);

        /**
        * Remove Vertex
        * @param v - the vertex need to remove
        */
        void removeVertex(Vertex v);
        
        /**
        * Get Edge
        * @param source - the source airport of Edge
        * @param destination - the destination airport of Edge
        */
        Edge getEdge(Vertex source, Vertex destination);

        /**
        * Get Incident Edge
        * @param v - the central vertex
        */
        vector<Edge> getIncidentEdge(Vertex v);

        /**
        * Insert edge
        * @param e - the edge need to insert
        */
        void insertEdge(Edge e);

        /**
        * Remove edge
        * @param e - the edge need to remove
        */
        void removeEdge(Edge e);

        /**
        * Distructor of Graph
        */
        ~Graph() {
            vertexList.clear();
            edgeList.clear();
        }

    private:
        map<string, Vertex> vertexList;
        map<string, Edge> edgeList;
};