# **CS 225 Data Structures**

# **Development**

## **Week 1 (2021/11/04)**

**Ideas:** Landmark path, Eulerian path

**Main problem:** Our project goal is to find the shortest route between two airports and display the route on the map.

**Dataset:** OpenFlights: route database and airport database

**Traversal:** BFS

**Covered Algorithm:** Shortest path - Floyd-Warshall Algorithm or Dijkstra’s Algorithm.

**Possible solutions for complex and uncovered options:**

Graphical output on projected onto a world map

Betweenness centrality mapping what airports are most important

Analyze the shorest path under different weather situations

## **Week 2 (2021/11/11)**

**Goals:** Download the datasets from the website, add the cs225 and catch files, organize all the files in the repository. 

**Description:** Downloaded datasets using the github from OpenFlights.org. Deleted several files which are not needed in the final project and saved as the data folder in the repository. Copied the cs225 folder (contains the necessary catch files, PNG files, make files) to the repository. Created tests folder, in which test cases will be written in the future. Created MakeFile and successfully runned the main.cpp. After arguing about the structure of the classes of our final project, we decided to create three classes: Graph, Functions, and Draw. The Graph class will contain the struct of vertices and edges. It will include all the member variables and member functions about the Graph. The Functions class will contain the BFS traversal and Dijkstra's Algorithm. The Draw class will contain the graphic mapping from our graph data to the map PNG. Then the basic codes and comments of the three classes are created.

## **Week 3 (2021/11/19)**

**Goals:** Our main goal is to revise the proposal and implement the storage of airport and airline data.

**Description:**

1. Revision of proposal. We have specified that edges are weighted by distance, how the distance is calculated by the latitude and longitude of two locations, and how we are going to store the airports and airlines data.

2. Storage of data. Since our airports and airlines data are in csv and .dat format, we need to transform them into String and Vector to process. Inspired by how we store cells in mp_mazes, we have two plans to implement the transformation:
   - The first method is using several 1-dimension vectors to store different string variables, for example, std::vector airportName, std::vector city, std::vector latitude. In this case, the pro is we can have a clear category of every type of variable. The con is if there is one missing element in a vector, the following element will not be in correspondence with the order of airports or airlines.
   - The second method is using a 2-dimension vector in the form of std::vector<std::vector<<std::string>>>. We will first store each element of an airport or airline into a 1-dimension vector, such as storing “London”, “43.035599” into std::vector londonAirport, and then push back every 1-dimension vector to the 2-dimension vector as a collection of all airports or airlines. In this case, we can make sure the order of each airport or airline is correct, and this is our final implementation.

## **Week 4 (from 2021/11/22 to 2021/11/28)**

**Goals:** Keeping implementation functions that reading and deal with the data form the dataset

**Description:**

1. Dealing with the data of airport.dat.
   - The first function is using std::map<std::string, std::vector<std::string>> to build up a dictionary so that we can get what we need faster. The keys of the map are airport_ids and the values is a 1D vectors which include airport_name, latitude and longitude in this order.
   - The second function is using std::map<std::string, std::string> to buuld up a dictionary so that we can get what we need faster. The key are IATAs and ICAOs and the values are the airport_ids because we need one of IATAs and ICAOs to search back airport_id. If we have two, it is better.

## **Week 5 (2021/12/02)**

**Goals:** Designing and developing the graph class, and its vertices and edges

**Description:**

1. Use the data exported from airport.dat and route.dat and construct vertices and edges. Then, add those vertices and edges to the graph as an adjacency list.
   - Use a map data structure to represent the adjacency list. The key of the map is the vertex, and the value of the map is a list of edges that are adjacent to the key vertex. Therefore, as long as we find the source and destination vertices ids, a new edge can be added quickly to the adjacency list.
   - We also come up with a more optimized solution. The graph with contain two maps. The first map will have string as the key and Vertex as the value. The second map will have string as the key and adjacency list as the value. Using this method, we don't have to construct a Vertex when adding new edges to the list. Also, we can check the vertex data quickly.
