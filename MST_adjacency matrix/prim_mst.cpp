// Prim's Algorithm implementation

#include <iostream>
#include <cstring>
#include <windows.h>

// #define V 7
#define INITIAL 100


int main(){
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    int V;
    std::cout << "Enter the total no of vertex in the graph (V): "; //we can put V default also (line 7)
    std::cin >> V;

//Way:1--input individual elements in matrix 

int G[V][V];
SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
std::cout << "Enter the elements of adjency matrix (weight of edges): \n";
    for(int i = 0; i < V; ++i)
       for(int j = 0; j < V; ++j)
       {
           std::cout << "Enter element G" << "[" << i << "]" << "[" << j << "]" << " : ";
           std::cin >> G[i][j];
       }

SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    std::cout << "The entered adjency matrix is : \n";
    for(int i = 0; i < V; ++i)
        for(int j = 0; j < V; ++j)
        {
            std::cout << G[i][j] << "  ";
            if(j == V - 1)
                std::cout << std::endl;
        }

   
    // //Way:2--Alternate way to input the adjency matrix (whole matrix input)

    // //Graph.1: G{V,E}
    // std::cout << "GRAPH: #1\n";
    // int G[V][V] = {
    //         //0 1 2 3 4 5 6 
    // /*0*/   { 0,4,0,5,2,0,0},
    // /*1*/   { 4,0,1,3,0,5,3},
    // /*2*/   { 0,1,0,8,0,9,0},
    // /*3*/   { 5,3,8,0,2,0,7},
    // /*4*/   { 2,0,0,2,0,6,3},
    // /*5*/   { 0,5,9,0,6,0,1},
    // /*6*/   { 0,3,0,7,3,1,0}
    // };

    // //Graph.2: G{V,E}
    // std::cout << "GRAPH: #2\n";
    //  int G[V][V] = {
    //         //0 1 2 3 4 5 6 
    // /*0*/   { 0,1,6,7,0,0,0},
    // /*1*/   { 1,0,9,0,0,0,0},
    // /*2*/   { 6,9,0,0,18,4,0},
    // /*3*/   { 7,0,0,0,11,0,12},
    // /*4*/   { 0,0,18,11,0,0,9},
    // /*5*/   { 0,0,4,0,0,0,0},
    // /*6*/   { 0,0,0,12,9,0,0}
    // };


    //  //Graph.3: G{V,E}
    //  std::cout << "GRAPH: #3\n";
    //  int G[V][V] = {
    //         //0 1 2 3 4 
    // /*0*/   { 0,5,15,10,0},
    // /*1*/   { 5,0,12,3,6},
    // /*2*/   { 15,12,0,0,0},
    // /*3*/   { 10,3,0,0,9},
    // /*4*/   { 0,6,0,9,0}
    
    // };
    


//Array which records vsited vertices
int visited_array[V];

//INitalize all positions as false initially
memset(visited_array, false, sizeof(visited_array));

int start_vertex = 0;

SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
//Initializing visited_array[0] as true to start with the 0th vertex
std::cout<< "Enter the Vertex to be the starting vertex for MST (0 to V-1)" << std::endl;
std::cin >> start_vertex;
visited_array[start_vertex]= true;


std::cout << std::endl;
SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
std::cout << "The vertex and thier edges to follow to find MST is in the table below." << std::endl;
SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
std::cout<< "-----------------------------------\n";
std::cout<< "Edge of              : Weight\n"; //edge and weight of MST
std::cout<< "(vertex1 to vertex2)   of the edge\n";
std::cout<< "-----------------------------------\n";
int n_edges =0;
while (n_edges < V-1){
    //variable to choose minimum value (weight) according to Prim's algorithm
    int min = INITIAL;

    //initialize vertex1 and vertex2 (two vertex in play)
    int vertex1=0, vertex2=0;

    //traversal along the row to pick every vertex
    for(int i = 0; i < V; ++i){

        //after picking a vertex check if it is inside the visited array
        if(visited_array[i]){

            //traversing along columns
            for(int j = 0; j < V; ++j){
                if(min > G[i][j]){
                    if ( G[i][j] && !visited_array[j]){
                        min = G[i][j];
                        vertex1=i;
                        vertex2=j;
                    }
                }
            }

        }
    }

    //display the edge with minimum value
    std::cout << "      " << vertex1 << " <-> " << vertex2 << "        :   " <<G[vertex1][vertex2] << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    visited_array[vertex2] = true;
    n_edges++;
    
}
SetConsoleTextAttribute(h,FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
return 0;
}