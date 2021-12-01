/**
 * This is graph.h file which is used to construct the basic variables used for functions
 */
#pragma once

#include <vector>
#include <string>
#include <map>

#include "read.h"

using namespace std;

class Graph {
    public:
        vector<vector<string>> route;
        map<string, vector<string>> airportPosition;
        map<string, string> airportIdDictionary;
        Graph();
        Graph(const string & routefile, const string & airportfile); 
    private:
        struct Vertex {
            string vertex_id;
            double latitude;
            double longitude;
        };

        struct Edge {
            // pair<string, string> edge_id;
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
};