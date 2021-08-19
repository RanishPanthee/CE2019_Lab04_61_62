#include<Graph.h>
int main()
{
 Graph s1;
 s1.addvertex(2);
 s1.addvertex(12);
 s1.addvertex(15);
 s1.addvertex(18);
 s1.addedge(2,12);
 s1.addedge(2,15);
 s1.addedge(2,18);
 cout<<s1.outdegree(2);
 cout<<s1.indegree(15);
 cout<<s1.degree(18);
 s1.areneighbours(2,15);
 s1.areneighbours(12,18);
 s1.numEdges();
 s1.numVertices();
 s1.neighbours(2);
 s1.removeEdge(2,15);
 s1.removeVertex(15);
 


}
