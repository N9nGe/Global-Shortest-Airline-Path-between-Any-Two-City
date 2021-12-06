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
#include "../functions.h"

using namespace std;

TEST_CASE("Reading file correctly",) {
    Graph g("route_testcase_1.dat", "Airport_testcase_1.dat");
    
    REQUIRE(g.route.size() == 30);
    REQUIRE(g.airportPosition.size() == 11);
    REQUIRE(g.airportIdDictionary["PEK"] == "3364");
    REQUIRE(g.airportIdDictionary["ZBLA"] == "3366");

    // 3U,4608,CTU,3395,PEK,3364,,0,330 321 320
    REQUIRE(g.route[0][2] == "CTU");
    REQUIRE(g.route[0][3] == "3395");
    REQUIRE(g.route[0][4] == "PEK");
    REQUIRE(g.route[0][5] == "3364");

    // 3U,4608,XNN,6366,ZHY,8043,,0,320
    REQUIRE(g.route[14][2] == "XNN");
    REQUIRE(g.route[14][3] == "6366");
    REQUIRE(g.route[14][4] == "ZHY");
    REQUIRE(g.route[14][5] == "8043");

    // CA,751,NGO,3942,PEK,3364,,0,738
    REQUIRE(g.route[29][2] == "NGO");
    REQUIRE(g.route[29][3] == "3942");
    REQUIRE(g.route[29][4] == "PEK");
    REQUIRE(g.route[29][5] == "3364");

    vector<string> PEK;
    vector<string> NGO;
    PEK.push_back("Beijing Capital International Airport");
    PEK.push_back("40.080101013183594");
    PEK.push_back("116.58499908447266");
    NGO.push_back("Chubu Centrair International Airport");
    NGO.push_back("34.8583984375");
    NGO.push_back("136.80499267578125");
    REQUIRE(g.airportPosition["3364"] == PEK);
    REQUIRE(g.airportPosition["3942"] == NGO);
}

TEST_CASE("Construct Graph successfully") {

}

TEST_CASE("BFS traversal 1") { 
    Graph g("route_testcase_1.dat", "Airport_testcase_1.dat");
    Functions test_1;
    vector<string> sum_1_id;
    vector<Graph::Vertex> sum_2;
    vector<string> sum_2_id;
    // need order of bfs to write sum_1
    sum_1_id.push_back("3364");
    sum_1_id.push_back("3395");
    sum_1_id.push_back("8043");
    sum_1_id.push_back("3393");
    sum_1_id.push_back("3372");
    sum_1_id.push_back("3373");
    sum_1_id.push_back("3942");
    sum_1_id.push_back("3366");
    sum_1_id.push_back("6366");
    sum_1_id.push_back("3371");
    sum_1_id.push_back("4144");
    sum_2 = test_1.BFS(g);
    for (size_t i = 0; i < sum_2.size(); i++) {
        sum_2_id.push_back(sum_2[i].vertex_id);
    }
    REQUIRE(sum_1_id == sum_2_id);
}

TEST_CASE("BFS traversal 2") { 
    Graph g("route_testcase_2.dat", "Airport_testcase_2.dat");
    Functions test_2;
    vector<string> sum_1_id;
    vector<Graph::Vertex> sum_2;
    vector<string> sum_2_id;
    // need order of bfs to write sum_1
    
    sum_2 = test_2.BFS(g);
    for (size_t i = 0; i < sum_2.size(); i++) {
        sum_2_id.push_back(sum_2[i].vertex_id);
    }
    REQUIRE(sum_1_id == sum_2_id);
}
