#include<Graph.h>

void Graph :: addvertex(int value){
  Vertex *ver=new Vertex(value);
  if (HEAD==NULL)  
  {
      HEAD=ver;
      TAIL=HEAD;
  }
  else{
      TAIL->down=ver;
      TAIL=TAIL->down;
     }
}


void Graph ::addedge(int vertex,int value)
{
    Edge *edg = new Edge(value);
    Vertex *temp;
    Vertex *temp=HEAD;
    while(temp->key!=Vertex && temp!=NULL){
        temp=temp->down;
    }
    if(temp!=NULL)
    Edge *edgptr=temp->right;
    if (edgptr==NULL)
    {
        temp->right=edg;
        cout<<"Edge is connected to vertex"<<vertex<<endl;
        else
        while(edgptr->next!=NULL)
        {
            edgptr=edgptr->next;
        }
        edgptr->next=edg;
        cout<<"Edge is connected to vertex:"<<vertex<<endl;
    }
}




int Graph :: outdegree(int vertex){
    int x=0;
    Vertex *ver = searchVertex(vertex);
    Edge *edg=Ver->right;
    if (edge!=NULL)
    {
        while(edg!=NULL)
        {x++;
        edg==edg->next;
        }
        return x;
    }
    else{
    return x;
    }

}


int Graph :: indegree(int vertex){
    Vertex *temp=HEAD;
    int x=0;
    while(temp!=NULL)
    {
        Edge *edg=temp->right;
        while(edg->key!=vertex && edg!=NULL){
            edg=edg->next;
        }
        if(edg!=NULL)
        {
            x++;
        }
        temp=temp->down;
        return x;

    }
}


int Graph :: degree(int vertex)
{
    int x =indegree(vertex);
    int y =outdegree(vertex);
    return9=(x+y);
}



bool Graph :: areneighbours(int vertex1,int vertex2)
{
    Edge *edg1=vertex1->right;
    Edge *edg2=vertex->right;

    Vertex *vertex1=searchvertex(vertex1);
    Vertex *vertex2=searchvertex(vertex2);
    while(edg1->key!=vertex2 && edg1!=NULL)
    {
        edg1=edg1->next;
    }
    while(edg2->key!=vertex1 && edg2!=NULL)
    {
        edg2=edg2->next;
    }
 if(edg1!=NULL && edg2!=NULL)
   return true;
   else
   return false;
}