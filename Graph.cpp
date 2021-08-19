#include "Graph.h"

bool Graph ::isEmpty()
{
    if (HEAD == NULL && TAIL == NULL)
    {
        return true;
        cout<<"Graph is Empty";
    }
    else
    {
        return false;
    }
}

void Graph ::addvertex(int value)
{
    Vertex *ver = new Vertex(value);
    if (HEAD == NULL)
    {
        HEAD = ver;
        TAIL = HEAD;
    }
    else
    {
        TAIL->down = ver;
        TAIL = TAIL->down;
    }
}

void Graph ::addedge(int vertex, int value)
{
    Edge *edg = new Edge(value);
    Vertex *temp = HEAD;
    while (temp != NULL && temp->key != vertex)
    {
        temp = temp->down;
    }

    if (temp == NULL)
    {
        cout << "INVALD VERTEX" << endl;
    }

    else
    {

        Edge *edgPtr = temp->right;
        if (edgPtr == NULL)
        {
            temp->right = edg;
            cout << endl
                 << "Edge Connected to : " << vertex << endl;
        }

        else
        {

            while (edgPtr->next != NULL)
            {
                edgPtr = edgPtr->next;
            }

            edgPtr->next = edg;
            cout << "Edge connected to : " << vertex << endl;
        }
    }
}

Vertex *Graph::searchvertex(int value)
{

    Vertex *temp = HEAD;

    while (temp != NULL && temp->key != value)
    {

        temp = temp->down;
    }

    if (temp == NULL)
    {
        return temp;
    }

    else
    {
        return temp;
    }
}

int Graph::outdegree(int vertex)
{
    int x = 0;
    Vertex *ver = searchvertex(vertex);
    Edge *edg = ver->right;
    if (edg != NULL)
    {
        while (edg != NULL)
        {
            x++;
            edg == edg->next;
        }
        return x;
    }
    else
    {
        return x;
    }
}

int Graph::indegree(int vertex)
{
    Vertex *temp = HEAD;
    int x = 0;
    while (temp != NULL)
    {
        Edge *edg = temp->right;
        while (edg != NULL && edg->key != vertex)
        {
            edg = edg->next;
        }
        if (edg != NULL)
        {
            x++;
        }
        temp = temp->down;
        return x;
    }
}

int Graph::degree(int vertex)
{
    int x = indegree(vertex);
    int y = outdegree(vertex);
    return (x + y);
}

bool Graph::areneighbours(int vertex1, int vertex2)
{

    Vertex *vertexx1 = searchvertex(vertex1);
    Vertex *vertexx2 = searchvertex(vertex2);

    Edge *edg1 = vertexx1->right;
    Edge *edg2 = vertexx2->right;

    while (edg1->key != vertex2 && edg1 != NULL)
    {
        edg1 = edg1->next;
    }
    while (edg2->key != vertex1 && edg2 != NULL)
    {
        edg2 = edg2->next;
    }
    if (edg1 != NULL && edg2 != NULL)
        return true;
    else
        return false;
}

void Graph::neighbours(int vertex)
{
    vec.clear();
    Vertex *temp = HEAD;
    while (temp != NULL)
    {

        Edge *edg = temp->right;
        if (vertex == temp->key)
        {

            while (edg != NULL)
            {
                vec.push_back(edg->key);
                edg = edg->next;
            }
        }
        else
        {
            while (edg != NULL && edg->key != vertex)
            {
                edg = edg->next;
            }

            if (edg != NULL)
            {
                vec.push_back(temp->key);
            }
        }

        temp = temp->down;
    }
}

int Graph::numEdges()
{

    Vertex *temp = HEAD;
    int i = 0;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            i++;
            temp = temp->down;
        }
        return i;
    }

    else
    {
        return i;
    }
}

int Graph::numVertices()
{
    Vertex *temp = HEAD;
    int i = 0;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            i++;
            temp = temp->down;
        }
        return i;
    }

    else
    {
        return i;
    }
}

void Graph::removeEdge(int vertex1, int vertex2)
{

    Vertex *ver1 = searchvertex(vertex1);
    Vertex *ver2 = searchvertex(vertex2);
    Edge *edg;
    Edge *prev = NULL;

    edg = ver1->right;
    if (edg != NULL)
    {
        while (edg != NULL && edg->key != ver2->key)
        {
            prev = edg;
            edg = edg->next;
        }

        if (prev == NULL)
        {
            ver1->right = edg->next;
            delete edg;
        }

        else if (edg != NULL)
        {
            prev->next = edg->next;
            delete edg;
        }
    }

    if (edg == NULL)
    {
        edg = ver2->right;
        prev = NULL;
        while (edg != NULL && edg->key != ver1->key)
        {
            prev = edg;
            edg = edg->next;
        }

        if (prev == NULL)
        {
            ver2->right = edg->next;
            delete edg;
        }

        else
        {
            Edge *temp = edg;
            prev->next = temp->next;
            delete temp;
        }
    }
}

void Graph::removeVertex(int vertex)
{
    Vertex *temp = searchvertex(vertex);
    Vertex *prev = NULL;
    Vertex *HEAD = HEAD;

    while (HEAD != NULL && HEAD->key != vertex)
    {
        prev = HEAD;
        HEAD = HEAD->down;
    }

    if (temp != NULL)
    {
        neighbours(vertex);
        for (int i = 0; i < vec.size(); i++)
        {
            removeEdge(vertex, vec.at(i));
        }

        if (prev == NULL)
        {
            HEAD = temp->down;
        }

        else
        {
            prev->down = temp->down;
        }

        delete temp;
    }

    else
    {
        cout << endl
             << "sorry operation failed" << endl;
    }
}
