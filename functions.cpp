#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> Functions::readRoute(const string & filename) {
    // initialize the variables
    vector<vector<string>> allRoute;
    ifstream dataSheet (filename);
    string airport;
    string airportId;
    string sourceAirport;
    string sourceAirportId;
    string destinationAirport;
    string destinationAirportId;
    string useless;

    if (dataSheet.is_open()) {
        while (dataSheet.good()) {
            vector<string> route;
            // given value
            getline(dataSheet, airport, ','); 
            getline(dataSheet, airportId, ',');
            getline(dataSheet, sourceAirport, ',');
            getline(dataSheet, sourceAirportId, ',');
            getline(dataSheet, destinationAirport, ',');
            getline(dataSheet, destinationAirportId, ',');
            getline(dataSheet, useless, '\n');
            // store value in single route
            route.push_back(airport);
            route.push_back(airportId);
            route.push_back(sourceAirport);
            route.push_back(sourceAirportId);
            route.push_back(destinationAirport);
            route.push_back(destinationAirportId);
            // route.push_back(useless);
            // store the route into the total route
            allRoute.push_back(route);
        }
    }
    // open out of the function, close in the function
    dataSheet.close();
    return allRoute;
}

