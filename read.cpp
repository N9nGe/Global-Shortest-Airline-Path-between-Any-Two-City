#include "read.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<string>> Read::readRoute(const string & filename) {
    // initialize the variables
    vector<vector<string>> allRoute;
    ifstream dataSheet (filename);
    string airline;
    string airlineId;
    string sourceAirport;
    string sourceAirportId;
    string destinationAirport;
    string destinationAirportId;
    string useless;

    if (dataSheet.is_open()) {
        while (dataSheet.good()) {
            vector<string> route;
            // given value
            getline(dataSheet, airline, ','); 
            getline(dataSheet, airlineId, ',');
            getline(dataSheet, sourceAirport, ',');
            getline(dataSheet, sourceAirportId, ',');
            getline(dataSheet, destinationAirport, ',');
            getline(dataSheet, destinationAirportId, ',');
            getline(dataSheet, useless, '\n');
            // store value in single route
            route.push_back(airline);
            route.push_back(airlineId);
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

map<string, vector<string>> Read::readAirportPosition(const string & filename) {
    // initialize the variables
    map<string, vector<string>> airport;
    ifstream dataSheet (filename);
    string airportId;
    string name;
    string city;
    string country;
    string iata;
    string icao;
    string latitude;
    string longitude;
    string useless;

    if (dataSheet.is_open()) {
        while (dataSheet.good()) {
            // given value
            getline(dataSheet, airportId, ','); 
            getline(dataSheet, name, ',');
            getline(dataSheet, city, ',');
            getline(dataSheet, country, ',');
            getline(dataSheet, iata, ',');
            getline(dataSheet, icao, ',');
            getline(dataSheet, latitude, ',');
            getline(dataSheet, longitude, ',');
            getline(dataSheet, useless, '\n');
            if (airport.find(airportId) == airport.end()) {
                airport[airportId].push_back(name);
                airport[airportId].push_back(latitude);
                airport[airportId].push_back(longitude);
            }
        }
    }
    // open out of the function, close in the function
    dataSheet.close();
    return airport;
}

map<string, string> Read::AirportIdDictionary(const string & filename) {
    // initialize the variables
    map<string, string> ID;
    ifstream dataSheet (filename);
    string airportId;
    string name;
    string city;
    string country;
    string iata;
    string icao;
    string useless;

    if (dataSheet.is_open()) {
        while (dataSheet.good()) {
            // given value
            getline(dataSheet, airportId, ','); 
            getline(dataSheet, name, ',');
            getline(dataSheet, city, ',');
            getline(dataSheet, country, ',');
            getline(dataSheet, iata, ',');
            getline(dataSheet, icao, ',');
            getline(dataSheet, useless, '\n');
            // We just store the effective iata and icao so that we can map to airport_id
            if (iata != "\\N" &&  icao != "\\N") {
                if (ID.find(iata) == ID.end()) {
                    ID[iata] = airportId;
                }
                if (ID.find(icao) == ID.end()) {
                    ID[icao] = airportId;
                }
            } else if (iata != "\\N" &&  icao == "\\N") {
                if (ID.find(iata) == ID.end()) {
                    ID[iata] = airportId;
                }
            } else if (iata == "\\N" &&  icao != "\\N") {
                if (ID.find(icao) == ID.end()) {
                    ID[icao] = airportId;
                }
            } else { }
        }
    }
    // open out of the function, close in the function
    dataSheet.close();
    return ID;
}
