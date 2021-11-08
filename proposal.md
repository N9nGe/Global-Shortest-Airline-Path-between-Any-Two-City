# **CS 225 Data Structures**

# **Final Proposal**

**Name: Gabriel Gao(ngao4), Yiming Zhao (yiming14), Tiancheng Xiao(txiao5), Haoyu Zhai(zhai11)**

## **1. Leading Question:**

The ﬁnal project is going to use OpenFlights as the dataset. The goal of the ﬁnal project is to ﬁnd the shortest route between two airports and display this route on a world map. The project will be a search tool that accepts two airport IDs that represent the starting point and destination. Then, the tool will output a string that includes all airport IDs in this path and an image (PNG) that displays the route on a world map.


## **2. Dataset Acquisition and Processing**

The dataset chosen for our ﬁnal project is OpenFlights. We are going to mainly use route databases and airport databases. The databases will be downloaded as .dat from the website. The route database contains the information such as airline ID, source airport, destination airport, and stops about every single route. The airport database contains the information such as airport ID, name, city, latitude, longitude, and altitude. Given the information above, we will ﬁnd the source airport and destination airport of each route, combine them with the corresponding geographical coordinates on the world map, and then use Dijkstra’s Algorithm to compute the shortest route between two speciﬁc airports. The database will have errors or missing entries. We could deal with these problems by identifying each problem. For example, if the entry is missing the plane type, which is trivial for our goal, we could treat this entry as a normal entry. But if the important information is missing, such as the destination airport, we will have to ignore the speciﬁc entry.


## **3. Graph Algorithms**

First, we are going to use the BFS algorithm to traverse the graph. The input of BFS function will be airport IATA or ICAO codes, and by traversing the graph we are able to keep record of all visited airports and routes.
Second, in order to ﬁnd the shortest path between two airports, we are going to use Dijkstra’s Algorithm. The input will be airport IATA or ICAO codes, latitude and longitude, and the expected output will be the shortest route between two given airports.
Finally, we will map each airport and route in the world map using the project to map based on data. We are going to use airport IATA or ICAO codes as input, and we are expecting a corresponding world map based on the airport and route database.


## **4. Timeline**

11/14 : Download the data, deal with errors and missing entries, store the data, and analyze the data structure. Get a general understanding of how to achieve our goal.

11/21: Finish implementation of the BFS traversal.

11/28: Finish implementation of Dijkstra's algorithm.

12/5: Finish implementation of graphic output of graph using project on to map based on data.

12/12: Do the ﬁnal revision of codes, presentations, and submit.

