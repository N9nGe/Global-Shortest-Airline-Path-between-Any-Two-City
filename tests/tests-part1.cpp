#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "../read.h"
#include "../graph.h"
#include "../cs225/catch/catch.hpp"

// using namespace std;

// TAST_CASE("Reading file correctly", "[mine]") {
//     Graph g("route_testcase_1.dat", "Airport_testcase_1.dat");
    
//     REQUIRE(g.route.size() == 30);
//     REQUIRE(g.airportPosition.size() == 30);
//     REQUIRE(g.airportIdDictionary["PEK"] == "3364");
//     REQUIRE(g.airportIdDictionary["ZBLA"] == "3366");

//     // 3U,4608,CTU,3395,PEK,3364,,0,330 321 320
//     REQUIRE(g.route[0][2] == "CTU");
//     REQUIRE(g.route[0][3] == "3395");
//     REQUIRE(g.route[0][4] == "PEK");
//     REQUIRE(g.route[0][5] == "3364");

//     // 3U,4608,XNN,6366,ZHY,8043,,0,320
//     REQUIRE(g.route[14][2] == "XNN");
//     REQUIRE(g.route[14][3] == "6366");
//     REQUIRE(g.route[14][4] == "ZHY");
//     REQUIRE(g.route[14][5] == "8043");

//     // CA,751,NGO,3942,PEK,3364,,0,738
//     REQUIRE(g.route[29][2] == "NGO");
//     REQUIRE(g.route[29][3] == "3942");
//     REQUIRE(g.route[29][4] == "PEK");
//     REQUIRE(g.route[29][5] == "3364");

//     vector<string> PEK;
//     vector<string> NGO;
//     PEK.push_back("Beijing Capital International Airport");
//     PEK.push_back("40.080101013183594");
//     PEK.push_back("116.58499908447266");
//     NGO.push_back("Chubu Centrair International Airport");
//     NGO.push_back("34.8583984375");
//     NGO.push_back("136.80499267578125");
//     REQUIRE(g.airportPosition["3364"] == PEK);
//     REQUIRE(g.airportPosition["3942"] == NGO);
// }