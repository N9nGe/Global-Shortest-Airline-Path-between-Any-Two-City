# **CS 225 Data Structures**

# **Final Proposal**

**Name: Gabriel Gao(ngao4), Yiming Zhao (yiming14), Tiancheng Xiao(txiao5), Haoyu Zhai(zhai11)**

## **1. Leading Question:**

The ﬁnal project is going to use OpenFlights as the dataset. The goal of the ﬁnal project is to ﬁnd the shortest route between two airports and display this route on a world map. The project will be a search tool that accepts two airport IDs that represent the starting point and destination. Then, the tool will output a string that includes all airport IDs in this path and an image (PNG) that displays the route on a world map.


## **2. Dataset Acquisition and Processing**

The dataset chosen for our final project is OpenFlights. We are going to mainly use route databases and airport databases. The databases will be downloaded as .dat from the website. The route database contains the information such as airline ID, source airport, destination airport, and stops about every single route. The airport database contains the information such as airport ID, name, city, latitude, longitude, and altitude. 

Given the information above, we will find the source airport and destination airport of each route, combine them with the corresponding geographical coordinates on the world map, and we will include all data given into a graph.

The airports in the airport database will be applied as the vertices in the graph, and the routes will be used as the edges in the graph. Because one route may contain multiple stops, we will implement additional functions that divide the route into subroutes representing the edges of the graph.

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

