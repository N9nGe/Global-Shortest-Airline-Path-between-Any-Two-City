# **CS 225 Data Structures**

# **Final Proposal**

**Name: Gabriel Gao(ngao4), Yiming Zhao (yiming14), Tiancheng Xiao(txiao5), Haoyu Zhai(zhai11)**

## **1. Leading Question**

The ﬁnal project is going to use OpenFlights as the dataset. The goal of the ﬁnal project is to ﬁnd the shortest route between two airports and display this route on a world map. The project will be a search tool that accepts two airport IDs that represent the starting point and destination. Then, the tool will output a string that includes all airport IDs in this path and an image (PNG) that displays the route on a world map.


## **2. Dataset Acquisition and Processing**

The dataset chosen for our final project is OpenFlights. We are going to mainly use route databases and airport databases. The databases will be downloaded as .dat from the website. 

An example of data format in the airport database is "Goroka Airport","Goroka","Papua New Guinea", "GKA", "AYGA", -6.08168983, 145.39199829, 5282,10, "U", "Pacific/Port_Moresby", "airport", "OurAirports". These entries correspond to the airport ID (airport_id), airport’s name (airport_name), city (city) and country (country) where the airport is located, airpot’s IATA (iata) and ICAO (icao) code, latitude (lat), longitude (long), altitude (alt), timezone of the airport (timezone), whether the airpot uses DST (dst), timezone in "tz" (Olson) forma, type of the airport (type), source of this data. (everything in the parentheses is the variable name, easier for future explanation)

An example of data format in the route database is "AA, 24, DRW, 3999, SYD, 3361, Y, 0, 737."These entries are code of the airline (airline), airline ID (airline_id), code of the source airport (source), source airpot ID (source_id), code of the destination airport (dest), Destination airport ID (dest_id), whether the flight is a codeshare(that is, not operated by Airline, but another carrier) (codeshare), number of stops on this flight (stops), codes for plane types (plane_type).  

Since the downloaded data is in csv format, we need to store them in other data structures for better implementation of algorithms. For the route dataset, we will use a 2-dimensional vector to store these data, in the form of std::vector<std::vector<<std::string>>>. We will first store each element of a route into a 1-dimensional vector, such as storing "AA", "24", "DRW", "3999", "SYD", "3361", "Y", "0", "737" into a 1-dimensional inner vector, and then push back every 1-dimensional vector to the 2-dimensional vector as a collection of all routes. In this way we have stored all data into a vector, and thus the search time would be constant. For the airport dataset, we will use a similar method, but we also recognize that because of different characteristics and uses in graph, there may be a more convenient data structure for the airport dataset, such as std::map, and we may have some adjustments as we proceed to algorithm implementation.

Given the information above, we will find the source airport and destination airport of each route, combine them with the corresponding geographical coordinates on the world map, and we will include all data given into a graph.

The airports in the airport database will be applied as the vertices in the graph, and the routes will be used as the edges in the graph. If one route may contain multiple stops, we will implement additional functions that divide the route into subroutes representing the edges of the graph.

Among all data entries provided, airport_id, lat, and long are the essential data entries that will be used to construct the vertices of the graph. All essential data entries can be derived directly from the database. Although those entries are essential, data entries such as the airport's name might be added to optimize the efficiency of displaying the results to the user. However, unlike the essential data entries, those unessential entries’ existences will not affect the completion of the graph algorithms’ functionalities.

Similarly, the essential data entries for the graph’s edges are source_id, dest_id, and distance. Source_id and dest_id can be directly derived from the database provided, and the distance will be derived by haversine formula that will be discussed later in this section. Hypothetically, the latitudes and longitudes of both source and destination airports should be added as the data entries for the edges to optimize the distance calculation performance. Keep in mind that if we already stored all data into a two dimensional array (or vector) when reading the data from the file, and the index of an airport’s data (including id and gps coordinates) directly maps to aiport_id, the search time for finding latitude and longitude of airports is constant O(1). Therefore, it would be unnecessary to include those to data entries into the edges.

The graph will be weighted, and the weight of each edge will be its distance from the source airport to the destination airport. We will apply the latitudes and longitudes of the airports obtained from the airport dataset and use haversine formula to calculate the distance between two airports. Assume that latitude_1 and longitude_1 are the latitude and longitude of the source airport, latitude_2 and longitude_2 are the latitude and longitude of the destination airport. All values used in trigonometry must be converted to radians by multiplying the value by pi/180.

Haversine formula would be:

a = (sin((latitude_2 - latitude_1)/2))^2 + cos(latitude_1) * cos(latitude_2) * (sin((longitude_2 - longitude_1 )/2))^2 

distance (in km) = 6371 * 2 * atan2(sqrt(a), sqrt(1 - a)) 

This is the distance calculated for every edge of the graph.

Finally, we will use Dijkstra’s Algorithm to compute the shortest route between two specific airports. The algorithm will be explained in depth in the Graph Algorithms section.

The database will have errors or missing entries. We could deal with these problems by identifying each problem. For example, if the entry is missing the plane type, which is trivial for our goal, we could treat this entry as a normal entry. But if the important information is missing, such as the destination airport, we will have to ignore the specific entry. 

## **3. Graph Algorithms**

First, we are going to use the BFS algorithm to traverse the graph. The input of the BFS function will be airport IATA or ICAO codes, and by traversing the graph we are able to keep record of all visited airports and routes.

To achieve the BFS traversal algorithm, we will have a similar approach to the BFS traversal for trees. The graph BFS traversal algorithm will also implement a queue. It will enqueue and dequeue in a loop until all vertices (airports) and edges (routes if there is no stop) are visited (more details are in pseudocode presented in the development log). However, because a graph may contain cycles, we will implement a function and an array that labels and stores all visited edges and vertices to avoid revisiting those components. The estimated runtime of the BFS traversal would be O(n + m), where “n” is the number of airports (vertices) and “m” is the number of routes (edges). 

However, the shortest distance is calculated based on the physical distance between airports derived from the latitude and longitude, edges will be considered as weighted, and a more complex algorithm will be implemented to complete the task. Therefore, in order to find the shortest path between two airports, we are going to use Dijkstra’s Algorithm. The input will be airport IATA or ICAO codes, latitude and longitude, and the expected output will be the shortest route between two given airports.

A big difference between the BFS traversal algorithm and Dijkstra’s Algorithm is that the queue data structure applied in the BFS is replaced with a priority queue to perform a sorted dequeue for the shortest path calculation. According to the pseudocode provided by the course notes, the runtime of Dijkstra’s Algorithm is O((n+m)log(n)).

Finally, we will map each airport and route in the world map using the project to map based on data. We are going to use airport IATA or ICAO codes as input, and we are expecting a corresponding world map based on the airport and route database.

A possible approach to achieve this functionality is to implement a basic search function that fetches the longitude and latitude of each airport. Then, we will display all airports in the path on the correct locations on the map. Since the sequence of vertices is derived from Dijkstra’s Algorithm, we will only need to search those airports. The runtime of searching one airport is O(n). However, there might be optimized functions discovered during the development.


## **4. Timeline**

11/14 : Download the data, deal with errors and missing entries, store the data, and analyze the data structure. Get a general understanding of how to achieve our goal.

11/21: Finish implementation of the BFS traversal. Build a test case that prints all traversal vertices from a starting point. Test if the actual printed vertices match the expected traversal vertices.

11/28: Finish implementation of Dijkstra's algorithm. Build two categories of test cases. The first category is finding the shortest path between two large international airports. The second category is finding the shortest path between two small non-international airports (this is more complex because more transfer flights are required). Test the algorithm with two types of test cases to check if the function operates correctly.

12/5: Finish implementation of graphic output of graph using project on to map based on data. Check if the actual PNG equals the expected PNG.

12/12: Do the ﬁnal revision of codes, presentations, and submit.

