#include "Graph.h"
#include <iostream>
#include <windows.h>

HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);
void graph1() {
  try {
    Graph graph(false);
    Vertex ktm(1011, "Kathmandu");
    Vertex jhapa(7897, "Jhapa");
    Vertex morang(7545, "Morang");
    Vertex illam(4440, "Illam");
    Vertex pokhara(3189, "Pokhara");
    Vertex chitwan(5014, "Chitwan");
    graph.addVertex(ktm);
    graph.addVertex(jhapa);
    graph.addVertex(morang);
    graph.addVertex(illam);
    graph.addVertex(pokhara);
    graph.addVertex(chitwan);
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "Vertices: ";
    std::cout << "Total vertices: " << graph.totalVertices() << std::endl;
    // std::cout << std::endl;
    graph.addEdge(ktm, chitwan, 100);
    graph.addEdge(chitwan, pokhara, 20);
    graph.addEdge(chitwan, illam, 600);
    graph.addEdge(chitwan, morang, 500);
    graph.addEdge(ktm, pokhara, 200);
    graph.addEdge(ktm, jhapa, 496);
    graph.addEdge(jhapa, morang, 32);
    graph.addEdge(jhapa, chitwan, 596);
    graph.addEdge(morang, ktm, 496 - 32);
    graph.addEdge(illam, jhapa, 75);
    graph.addEdge(pokhara, jhapa, 696);
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\nAdjacenecy List: " << std::endl;
    graph.adjacencyList();

    std::cout << "\n\n";
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << "Prim's MST:\n" << std::endl;
    int total = graph.totalVertices();
    graph.prim(pokhara, total);

  } catch (std::string error) {
    std::cout << error << std::endl;
  }
  SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void graph2() {
    try {
    Graph graph(false);
    Vertex one(1011, "Point1");
    Vertex two(7897, "Point2");
    Vertex three(7545, "Point3");
    Vertex four(4440, "Point4");
    Vertex five(3189, "Point5");
    Vertex six(5014, "Point6");
    graph.addVertex(one);
    graph.addVertex(two);
    graph.addVertex(three); 
    graph.addVertex(four);
    graph.addVertex(five);
    graph.addVertex(six);
     SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "Vertices: ";
    std::cout << "Total vertices: " << graph.totalVertices() << std::endl;
    // std::cout << std::endl;
    graph.addEdge(one, four, 10);
    graph.addEdge(one, five, 20);
    graph.addEdge(two, one, 30);
    graph.addEdge(two, five, 15);
    graph.addEdge(two, six, 25);
    graph.addEdge(three, six, 35);
    graph.addEdge(six, four, 32);
    graph.addEdge(four, three, 10);
    graph.addEdge(five, four, 16);
    graph.addEdge(six, five, 25);
    graph.addEdge(three, one , 19);
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\nAdjacenecy List: " << std::endl;
    graph.adjacencyList();

    std::cout << "\n\n";
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << "Prim's MST:\n" << std::endl;
    int total = graph.totalVertices();
    graph.prim(five, total);

  } catch (std::string error) {
    std::cout << error << std::endl;
  }
  SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
  
}

void graph3() {
    try {
    Graph graph(false);
    Vertex computer(1011, "Computer");
    Vertex electronic(7897, "Electronics");
    Vertex pharmacy(7545, "Pharmacy");
    Vertex geomatics(4440, "Geomatics");
    Vertex arch(3189, "Architecture");
    Vertex civil(5014, "Civil");
    graph.addVertex(computer);
    graph.addVertex(electronic);
    graph.addVertex(pharmacy);
    graph.addVertex(geomatics);
    graph.addVertex(arch);
    graph.addVertex(civil);
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "Vertices: ";
    std::cout << "Total vertices: " << graph.totalVertices() << std::endl;
    // std::cout << std::endl;
    graph.addEdge(computer, geomatics, 7);
    graph.addEdge(computer, civil, 6);
    graph.addEdge(civil, geomatics, 2);
    graph.addEdge(pharmacy, electronic, 1);
    graph.addEdge(pharmacy, civil, 9);
    graph.addEdge(arch, pharmacy, 4);
    graph.addEdge(pharmacy, geomatics, 3);
    graph.addEdge(computer, arch, 7);
    graph.addEdge(civil, electronic, 5);
    graph.addEdge(geomatics, arch, 9);
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\nAdjacenecy List: " << std::endl;
    graph.adjacencyList();

    std::cout << "\n\n";
    SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << "Prim's MST:\n" << std::endl;
    int total = graph.totalVertices();
    graph.prim(arch, total);

  } catch (std::string error) {
    std::cout << error << std::endl;
  }
  SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main() {
    
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
    std::cout << "\nGraph #1" << std::endl;
    graph1();
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
    std::cout << "\nGraph #2" << std::endl;
    graph2();
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
    std::cout << "\nGraph #3" << std::endl;
    graph3();
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
    std::cout << "---------------------------------------------------------------------------" <<  std::endl;
}