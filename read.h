/**
*This is read.h which is used to read the data from the dataset that we have 
*/

#pragma once
#include <string>
#include <vector>

using namespace std;

class Read {
    public:
        vector<vector<string>> readRoute(const string & filename);

};