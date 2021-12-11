/**
*This is read.h which is used to read the data from the dataset that we have 
*/

#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class Read {
    public:
        // put everyting we need into a 2D vector
        vector<vector<string>> readRoute(const string & filename);
        // The key is airport_id and the value is the vector of (latitude, longitude)
        map<string, vector<string>> readAirportPosition(const string & filename);
        // The key is IATA or ICAO and the value is the airport_id
        map<string, string> AirportIdDictionary(const string & filename);
};