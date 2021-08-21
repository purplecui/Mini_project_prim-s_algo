#include "Graph.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

bool Graph::isEmpty() { return HEAD == nullptr ? true : false; }

bool Graph::isDirected() { return isDiGraph; }

void Graph::addVertex(Vertex newVertex) {
  if (!cityCodeExists(newVertex.cityCode)) {
    // add to head
    Vertex *vertexToAdd = new Vertex(newVertex);
    codeToVertexMap[newVertex.cityCode] = vertexToAdd;
    if (isEmpty()) {
      HEAD = vertexToAdd;
    } else {
      vertexToAdd->next = HEAD;
      HEAD = vertexToAdd;
    }
  } else
    throw std::string("City already exists in the graph");
}

bool Graph::cityCodeExists(int cityCode) {
  Vertex *temp = HEAD;

  // traversing down the vertices
  while (temp != nullptr) {
    if (cityCode == temp->cityCode) {
      return true; // return true if cityCode exists
    }
    temp = temp->next;
  }
  return false;
}

bool Graph::edgeExists(Vertex from, Vertex to) {
  Vertex *temp = HEAD;

  // traversing down the vertices
  while (temp != nullptr) {
    if (temp->cityCode == from.cityCode) {
      // vertex 1(from) is found
      Edge *tempRight = temp->edgesHead;
      // traversing right of the vertex 1
      while (tempRight != nullptr) {
        if (tempRight->vertex->cityCode == to.cityCode)
          return true; // return true if edge exists
        tempRight = tempRight->right;
      }
    }
    temp = temp->next;
  }
  return false;
}

void Graph::addEdge(Vertex fromVertex, Vertex toVertex,
                    int distanceInKilometers) {

  // check if the two vertices exists
  Vertex *from = nullptr;
  Vertex *to = nullptr;
  Vertex *temp = HEAD;
  while (temp != nullptr) {
    if (temp->cityCode == fromVertex.cityCode)
      from = temp;
    if (temp->cityCode == toVertex.cityCode)
      to = temp;
    temp = temp->next;
  }
  if (!from || !to)
    throw std::string("Cannot add path, One or more city doesnot exist");

  // check if the edge exists
  bool exists = edgeExists(fromVertex, toVertex);

  if (exists)
    throw std::string("Path already exists");

  if (fromVertex.cityCode == toVertex.cityCode)
    throw std::string("Cannot add path between same city");

  if (isDirected()) {
    Edge *newEdge = new Edge(toVertex, distanceInKilometers);
    // add to head
    if (from->edgesHead == nullptr) {
      from->edgesHead = newEdge;
    } else {
      newEdge->right = from->edgesHead;
      from->edgesHead = newEdge;
    }
  } else {
    // for undirected we add 2 edges
    Edge *newEdgeOne = new Edge(toVertex, distanceInKilometers);
    Edge *newEdgeTwo = new Edge(fromVertex, distanceInKilometers);
    // add to head of vertex 1
    if (from->edgesHead == nullptr) {
      from->edgesHead = newEdgeOne;
    } else {
      newEdgeOne->right = from->edgesHead;
      from->edgesHead = newEdgeOne;
    }

    // add to head of vertex 2
    if (to->edgesHead == nullptr) {
      to->edgesHead = newEdgeTwo;
    } else {
      newEdgeTwo->right = to->edgesHead;
      to->edgesHead = newEdgeTwo;
    }
  }
}

int Graph::totalVertices() {
  int totalVertices = 0;
  Vertex *temp = HEAD;

  // traversing down the vertices
  while (temp != nullptr) {
    totalVertices++; // updating count
    temp = temp->next;
  }
  return totalVertices;
}

void Graph::adjacencyList() {
  Vertex *tempDown = HEAD;

  // traversing down the vertices
  while (tempDown != nullptr) {
    Edge *tempRight = tempDown->edgesHead;
    std::cout << tempDown->cityName
              << ((tempDown->edgesHead == nullptr) ? " -->" : "");

    // traversing the edges for eac vertex
    while (tempRight != nullptr) {
      std::cout << " -- (" << tempRight->distanceInKilometers << ") --> "
                << tempRight->vertex->cityName;
      tempRight = tempRight->right;
    }
    tempDown = tempDown->next;
    std::cout << "\n";
  }
}



void Graph::prim(Vertex startingVetrex, int totalVertices) {

  bool vertexDoesNotExists = codeToVertexMap.find(startingVetrex.cityCode) == codeToVertexMap.end();
  if (vertexDoesNotExists)
    throw std::string("Error");

  Vertex *vertex = codeToVertexMap[startingVetrex.cityCode];

  std::unordered_map<int, Vertex *> visited; // stores visited vertices
  visited[vertex->cityCode] = vertex;
  int length = visited.size();

  // We loop until we traverse through n-1 vertices
  while (length <= (totalVertices - 1)) {
      Vertex *from = nullptr;
    Edge *smallest = nullptr;
    // we loop through each visited vertices
    for (auto vertex : visited) {
      Edge *edges = vertex.second->edgesHead;

      // for each visited vertices, we check the edges
      while (edges != nullptr) {

        // checks if the vertex is visitied or not
        bool isNotVisited = visited.find(edges->vertex->cityCode) == visited.end();

        if (isNotVisited) {

          // if the smallest not visited is not yet found, we update the smallest
          if (!smallest)  {
            smallest = edges;
            from = vertex.second;
          }

          // if the new edge is smaller than the smallest, we update the smallest
          if (edges->distanceInKilometers <= smallest->distanceInKilometers) {
            smallest = edges;
            from = vertex.second;
          }
        }
        edges = edges->right;
      }
    }

    vertex = codeToVertexMap[smallest->vertex->cityCode]; // taking out the smallest(found above) vertex from vertex map
    visited[vertex->cityCode] = vertex; // mark it as visited
    length = visited.size(); // update the value of lenth
    std::cout << from->cityName << "--- " << smallest->distanceInKilometers
              << " ---" << vertex->cityName << std::endl;  // print out the link
    ;
  }
}