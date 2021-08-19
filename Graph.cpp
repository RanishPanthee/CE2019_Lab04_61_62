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
{	Edge *edge = new Edge(value);
    Vertex *temp = HEAD;
    while(temp!= NULL  &&  temp->key != vertex){
        temp = temp->down;
    }
    
    if(temp == NULL){
        cout<<"INVALD VERTEX"<<endl;
    }
    
    else{
        
        Edge *edgePtr = temp->right;
        if(edgePtr == NULL){
            temp->right = edge;
            cout<<endl<<"Edge Connected to : "<<vertex<<endl;
        }
        
        else{
            
            while(edgePtr->next != NULL){
                edgePtr = edgePtr->next;
            }
            
            edgePtr->next=edge;
            cout<<"Edge connected to : "<<vertex<<endl;
            
        }
        
    }
	
   
}

Vertex* Graph::searchvertex(int value){
    
    Vertex *temp=HEAD;
    
    while(temp!= NULL  &&  temp->key != value){
        
        temp=temp->down;
    }
    
    if(temp==NULL){
        return temp;
    }
    
    else{
        return temp;
    }
    
}



int Graph::outdegree(int vertex){
    int x=0;
    Vertex *ver = searchvertex(vertex);
    Edge *edg=ver->right;
    if (edg!=NULL)
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


int Graph::indegree(int vertex){
    Vertex *temp=HEAD;
    int x=0;
    while(temp!=NULL)
    {
        Edge *edg=temp->right;
        while(edg!=NULL&& edg->key!=vertex){
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


int Graph::degree(int vertex)
{
    int x =indegree(vertex);
    int y =outdegree(vertex);
    return (x+y);
}



bool Graph::areneighbours(int vertex1,int vertex2)
{
    
	Vertex *vertexx1=searchvertex(vertex1);
    Vertex *vertexx2=searchvertex(vertex2);
    
	Edge *edg1=vertexx1->right;
    Edge *edg2=vertexx2->right;

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
{	Edge *edge = new Edge(value);
    Vertex *temp = HEAD;
    while(temp!= NULL  &&  temp->key != vertex){
        temp = temp->down;
    }
    
    if(temp == NULL){
        cout<<"INVALD VERTEX"<<endl;
    }
    
    else{
        
        Edge *edgePtr = temp->right;
        if(edgePtr == NULL){
            temp->right = edge;
            cout<<endl<<"Edge Connected to : "<<vertex<<endl;
        }
        
        else{
            
            while(edgePtr->next != NULL){
                edgePtr = edgePtr->next;
            }
            
            edgePtr->next=edge;
            cout<<"Edge connected to : "<<vertex<<endl;
            
        }
        
    }
	
   
}

Vertex* Graph::searchvertex(int value){
    
    Vertex *temp=HEAD;
    
    while(temp!= NULL  &&  temp->key != value){
        
        temp=temp->down;
    }
    
    if(temp==NULL){
        return temp;
    }
    
    else{
        return temp;
    }
    
}



int Graph::outdegree(int vertex){
    int x=0;
    Vertex *ver = searchvertex(vertex);
    Edge *edg=ver->right;
    if (edg!=NULL)
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


int Graph::indegree(int vertex){
    Vertex *temp=HEAD;
    int x=0;
    while(temp!=NULL)
    {
        Edge *edg=temp->right;
        while(edg!=NULL&& edg->key!=vertex){
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


int Graph::degree(int vertex)
{
    int x =indegree(vertex);
    int y =outdegree(vertex);
    return (x+y);
}



bool Graph::areneighbours(int vertex1,int vertex2)
{
    
	Vertex *vertexx1=searchvertex(vertex1);
    Vertex *vertexx2=searchvertex(vertex2);
    
	Edge *edg1=vertexx1->right;
    Edge *edg2=vertexx2->right;

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
