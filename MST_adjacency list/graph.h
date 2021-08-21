#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

class Edge;

class Vertex {
public:
  int cityCode;
  std::string cityName;
  Vertex *next;    // Pointer to the next vertex
  Edge *edgesHead; // Pointer to the edges

  Vertex() : next(nullptr) {}
  Vertex(int cityCode, std::string cityName)
      : cityCode(cityCode), cityName(cityName), next(nullptr),
        edgesHead(nullptr) {}
};

class Edge {
public:
  int distanceInKilometers;
  Vertex *vertex;
  Edge *right;
  // Edge *left;

  Edge(Vertex vertex, int distanceInKilometers)
      : vertex(new Vertex(vertex)), distanceInKilometers(distanceInKilometers),
        right(nullptr) {}

  ~Edge() { delete vertex; }
};

class Graph {

private:
  Vertex *HEAD;
  bool isDiGraph;
  std::unordered_map<int, Vertex *> codeToVertexMap;

public:
  Graph() : HEAD(nullptr), isDiGraph(true) {}
  Graph(bool isDirected) : HEAD(nullptr), isDiGraph(isDirected) {}

  void prim(Vertex startingVetrex, int totalVertices);

  // Checks if the graph is empty
  bool isEmpty();

  // Checks if the graph is directed
  bool isDirected();

  // Prints out the adjacency list
  void adjacencyList();

  // Adds a vertex to the graph
  void addVertex(Vertex newVertex); 

  // Chcks if a vertex with given key exists or not
  bool cityCodeExists(int cityCode); 

  // Adds an edge between two vertices
  void addEdge(Vertex fromVertex, Vertex toVertex,
               int distanceInKilometers); 

  // Checks if an edge exists between two vertices
  bool edgeExists(Vertex from, Vertex to);

  // Returns the total no of vertices in the graph
  int totalVertices();
};