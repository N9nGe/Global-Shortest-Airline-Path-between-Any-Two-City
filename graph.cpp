#include "graph.h"

using namespace std;

Graph::Graph(const string & routefile, const string & airportfile) {
    route = readRoute(routefile);
    airportPosition = readAirportPosition(airportfile);
    airportIdDictionary = AirportIdDictionary(airportfile);
}