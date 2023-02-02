# ngao4-yiming14-zhai11-txiao5
Final Project repo for ngao4-yiming14-zhai11-txiao5

# **Final project: Graph Algorithms with Open Flights**

**Name: Gabriel Gao(ngao4), Yiming Zhao (yiming14), Tiancheng Xiao(txiao5), Haoyu Zhai(zhai11)**

## **Project presentation video**
https://youtu.be/Bsvvu_ICgtQ

## **Project functionality**

The project is able to:
- Construct a weighted and directed graph consisting of airports (vertices) and routes (edges) automatically using string data from .dat files
- Achieve graph traversal through all airports (vertices) and routes (edges) in Open Flights using Breadth-First Traversal (BFS)
- Find the path that has the shortest distance between two airports using Dijkstra's Algorithm
- Display the airports and the path on a PNG image using Bresenham’s Line Drawing Algorithm

## **Data**

All databases used in this project are provided by Open Flights. Specifically, airports.dat and routes.dat are the full-scale databases to construct the vertices (airports) and edges (routes) of the graph. All databases are stored in the “/data” folder of the project directory.

Users can also create their own preferred .dat databases for other transportation applications using the following format:

Vertices (airports or other stations)

    vertex_id,"Name","City","Country","Code_type_1","Code_type_2",latitude,longitude,altitude,timezone,"DST","Tz database time zone","Type","Source (where data is from)"

Edges (routes between two airports or two stations)

    Airline,Airline ID,Source airport,Source airport ID,Destination airport,Destination airport ID,Codeshare,number of stops,Equipment


## **Major code** (Detailed description of each function and the instructions for use are in the .h files) 

Major code files are in the project directory. They are:
- read.h and read.cpp

  Read class includes functions that read, process, and import string data from .dat into more efficient C++ data structures for other classes to access. The class contains three public functions that can be called in other classes: readRoute, readAirportPosition, and AirportIdDictionary.

- graph.h and graph.cpp

  Graph class includes constructors and default graph functions (addVertex, addEdge, …) required to build a weighted graph containing an adjacency list. The class also includes two nested structs: Vertex and Edge. Different from the default vertex and edge, the nested Vertex includes the latitude and longitude of the airport, and the nested Edge contains a weight (distance) between two vertices.

- functions.h and functions.cpp

  Functions class contains two functions: BFS and Dijkstra. BFS is developed to perform graph traversal, and Dijkstra algorithm is developed to find the shortest path between two vertices. Both functions are public and can be called by other classes.

- draw.h and draw.cpp

  Draw class contains functions that draw points on a PNG using vertices given, draw lines on a PNG according to edges, draw the shortest path (with points and lines) between two airports on a world map, and write the PNG to a file.

## **Main.cpp and using different input data**

Main.cpp is divided into 4 sections and each section has a comment above describing its functionality. Combined together, 4 sections can perform the functionalities: constructing the graph, BFS traversal, draw the traversal to an image map, find the shortest path between two airports, and draw the path on a map.

Users can also focus on a specific functionality by commenting other sections out. However, it is recommended to keep the graph constructed for all usages.

Additionally, users can modify the airports and routes databases, if they have customized databases, by changing the values of airportsDir and routesDir at line 15 and 16 to:

	string airportsDir = “airport database file directory”;
	string routesDir = “route database file directory”;

Users can change different airport ID to start the BFS traversal by changing bfsStartId at line 20:

  string bfsStartId = "starting airport’s id";

Users can also input different airport IDs to find the shortest path between them. To achieve this, users can modify the values of startId and endId at line 54 and 56:

	string startId = “starting airport’s id”;
	string endId = “destination airport’s id”;

## **Compiling and running the code**

The Makefile for this project will produce an main executable (all lower case main). The following command will make main:

    make

Then run then program:

    ./main

## **Results**

Main class will output the first airport visited and the last airport visited in the BFS traversal and the size of the connected graph in the terminal. Then the class will store a map image consisting of all routes and airports to "all_airlines.png" in the project directory. Also, the class will output all airports contained in the shortest path between two airports and store the path as an image named as "output_map.png" in the project directory.

Result in the terminal:

![terminal result](./document_images/readme_imgs/result1.png)


BFS Traversal on the map "all_airlines.png"

![map1](./all_airlines.png)


Shortest path on the map "output_map.png"

![map2](./output_map.png)


## **Test cases**

The project also has auto test code that is located in the “/tests” folder. Additional databases that are used in the test suite is located in the project directory: “Airport_testcase_1.dat”, “Airport_testcase_2.dat”, “route_testcase_1.dat”, and “route_testcase_2.dat”. 

Airports in databases are arbitrarily selected from the full-scale databases, and corresponding routes are added to the route test case database. We used smaller-scaled databases because the expected results in test cases are manually calculated by hand to maintain the accuracy and purpose of the autotest. However, the code works perfectly with full-scale databases in main.cpp.

There are 4 types of test cases:
- Reading file correctly
- Construct Graph successfully
- BFS traversal
- Shortest Path

## **Testing**

The Makefile will also produce a test executable. The following command will make test and run the test program:

    make test
    ./test

To run a specific test case:

    ./test "Reading file correctly" #Reading file correctly
    ./test "Construct Graph successfully" #Construct Graph successfully
    ./test "BFS traversal 1" #BFS traversal
    ./test "Shortest Path_1""NGO--CTU" #Shortest Path between NGO to CTU

WARNING
-------

You **SHOULD NOT** copy these code into your own ECE 391 project without proper citation. Doing this is a violation of academic integrity. **You have been warned.**

I do not own the copyright to artworks in this project. They are downloaded from websites that provide these artworks for free.

This is a collaborative project by 4 students. See commit log for individual contributions.

Overview
--------

This is the final project for my ECE 391 course taken in UIUC. The project consists of implementing an Linux-like operating system.

Features
--------

- Required by course:
  - Memory paging
  - i8259 PIC interrupt handling
  - Exception handling
  - Keyboard input buffer
  - In memory read-only filesystem
  - Round-robin scheduling based on Programmable Interrupt Timer

How to run
----------

If using latest QEMU:

`qemu-system-i386 -hda "student-distrib/mp3.img" -m 512 -name test -gdb tcp:127.0.0.1:1234`
If using QEMU provided by this course:

`qemu-system-i386 -hda "student-distrib/mp3.img" -m 512 -name test -gdb tcp:127.0.0.1:1234`


Original README by UIUC
=======================

ACADEMIC INTEGRITY
-----
Please review the University of Illinois Student Code before starting,
particularly all subsections of Article 1, Part 4 Academic Integrity and Procedure [here](http://studentcode.illinois.edu/article1_part4_1-401.html).

**§ 1‑402 Academic Integrity Infractions**

(a).	Cheating. No student shall use or attempt to use in any academic exercise materials, information, study aids, or electronic data that the student knows or should know is unauthorized. Instructors are strongly encouraged to make in advance a clear statement of their policies and procedures concerning the use of shared study aids, examination files, and related materials and forms of assistance. Such advance notification is especially important in the case of take-home examinations. During any examination, students should assume that external assistance (e.g., books, notes, calculators, and communications with others) is prohibited unless specifically authorized by the Instructor. A violation of this section includes but is not limited to:

(1)	Allowing others to conduct research or prepare any work for a student without prior authorization from the Instructor, including using the services of commercial term paper companies. 

(2)	Submitting substantial portions of the same academic work for credit more than once or by more than one student without authorization from the Instructors to whom the work is being submitted. 

(3) Working with another person without authorization to satisfy an individual assignment.

(b) Plagiarism. No student shall represent the words, work, or ideas of another as his or her own in any academic endeavor. A violation of this section includes but is not limited to:

(1)	Copying: Submitting the work of another as one’s own. 

(2)	Direct Quotation: Every direct quotation must be identified by quotation marks or by appropriate indentation and must be promptly cited. Proper citation style for many academic departments is outlined in such manuals as the MLA Handbook or K.L. Turabian’s A Manual for Writers of Term Papers, Theses and Dissertations. These and similar publications are available in the University bookstore or library. The actual source from which cited information was obtained should be acknowledged.

(3)	Paraphrase: Prompt acknowledgment is required when material from another source is paraphrased or summarized in whole or in part. This is true even if the student’s words differ substantially from those of the source. A citation acknowledging only a directly quoted statement does not suffice as an acknowledgment of any preceding or succeeding paraphrased material. 

(4)	Borrowed Facts or Information: Information obtained in one’s reading or research that is not common knowledge must be acknowledged. Examples of common knowledge might include the names of leaders of prominent nations, basic scientific laws, etc. Materials that contribute only to one’s general understanding of the subject may be acknowledged in a bibliography and need not be immediately cited. One citation is usually sufficient to acknowledge indebtedness when a number of connected sentences in the paper draw their special information from one source.

(c) Fabrication. No student shall falsify or invent any information or citation in an academic endeavor. A violation of this section includes but is not limited to:

(1)	Using invented information in any laboratory experiment or other academic endeavor without notice to and authorization from the Instructor or examiner. It would be improper, for example, to analyze one sample in an experiment and covertly invent data based on that single experiment for several more required analyses. 

(2)	Altering the answers given for an exam after the examination has been graded. 

(3)	Providing false or misleading information for the purpose of gaining an academic advantage.

(d)	Facilitating Infractions of Academic Integrity. No student shall help or attempt to help another to commit an infraction of academic integrity, where one knows or should know that through one’s acts or omissions such an infraction may be facilitated. A violation of this section includes but is not limited to:

(1)	Allowing another to copy from one’s work. 

(2)	Taking an exam by proxy for someone else. This is an infraction of academic integrity on the part of both the student enrolled in the course and the proxy or substitute. 

(3)	Removing an examination or quiz from a classroom, faculty office, or other facility without authorization.

(e)	Bribes, Favors, and Threats. No student shall bribe or attempt to bribe, promise favors to or make threats against any person with the intent to affect a record of a grade or evaluation of academic performance. This includes conspiracy with another person who then takes the action on behalf of the student.

(f)	Academic Interference. No student shall tamper with, alter, circumvent, or destroy any educational material or resource in a manner that deprives any other student of fair access or reasonable use of that material or resource. 

(1)	Educational resources include but are not limited to computer facilities, electronic data, required/reserved readings, reference works, or other library materials. 

(2)	Academic interference also includes acts in which the student committing the infraction personally benefits from the interference, regardless of the effect on other students.


LEGAL
-----
Permission to use, copy, modify, and distribute this software and its
documentation for any purpose, without fee, and without written agreement is
hereby granted, provided that the above copyright notice and the following
two paragraphs appear in all copies of this software.

IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO
ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
DAMAGES ARISING OUT  OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION,
EVEN IF THE AUTHOR AND/OR THE UNIVERSITY OF ILLINOIS HAS BEEN ADVISED
OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHOR AND THE UNIVERSITY OF ILLINOIS SPECIFICALLY DISCLAIM ANY
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE

PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND NEITHER THE AUTHOR NOR
THE UNIVERSITY OF ILLINOIS HAS ANY OBLIGATION TO PROVIDE MAINTENANCE,
SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
