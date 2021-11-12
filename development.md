# **CS 225 Data Structures**

# **Development**

## **Week 1 (2021/11/04)**

**Ideas:** Landmark path, Eulerian path

**Main problem:** Our project goal is to find the shortest route between two airports and display the route on the map.

**Dataset:** OpenFlights: route database and airport database

**Traversal** BFS

**Covered Algorithm**: Shortest path - Floyd-Warshall Algorithm or Dijkstra’s Algorithm.

**Possible solutions for complex and uncovered options**: 

Graphical output on projected onto a world map

Betweenness centrality mapping what airports are most important

Analyze the shorest path under different weather situations

## **Week 2 (2021/11/11)**

**Goals:** Download the datasets from the website, add the cs225 and catch files, organize all the files in the repository. 

**Description:** Downloaded datasets using the github from OpenFlights.org. Deleted several files which are not needed in the final project and saved as the data folder in the repository. Copied the cs225 folder (contains the necessary catch files, PNG files, make files) to the repository. Created tests folder, in which test cases will be written in the future. Created MakeFile and successfully runned the main.cpp. After arguing the structure of the classes of our final project, we decided to create three classes: Graph, Algorithm, and Draw. The Graph class will contain the struct of vertices and edges. It will include all the member variables and member functions about the Graph. The Algorithm class will contain the BFS traversal and Dijkstra's Algorithm. The Draw class will contain the graphic mapping from our graph data to the map PNG. 
