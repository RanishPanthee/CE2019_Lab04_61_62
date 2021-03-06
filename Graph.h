#include <iostream>
#include <vector>
using namespace std;
class Edge{
    public:
    int key;
    Edge *next;
    Edge(int value)
    {
    key=value;
    next=NULL;
    }
};
class Vertex
{
     public:
    int key;
    Vertex *down;
    Edge *right;
    Vertex(int value){
       key=value;
       down=NULL;
       right=NULL;
    }
};
class Graph{
    public:
    Vertex *HEAD;
    Vertex *TAIL;
    Graph(){
        HEAD=NULL;
    }
     void addvertex(int value);
     void addedge(int vertex,int value);
     Vertex* searchvertex(int value);
     int indegree(int vertex);
     int outdegree(int vertex);
     int degree(int vertex);
     bool areneighbours(int ver1,int ver2);
     bool isEmpty();
     void neighbours(int vertex);
     int numEdges();
     int numVertices();
     void removeEdge(int ver1,int ver2);
     void removeVertex(int vertex);


};
