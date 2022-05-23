/*
There are flight paths between cities. If there is a flight between city A
and city B then there is an edge between the cities. The cost of the edge can be the time that
flight takes to reach city B from A or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency list
representation of the graph or use adjacency matrix representation of the graph. Justify the
storage representation used.

Algorithm:
Graph creation using Adjacency Matrix
1. Declare an array of M[size][size] which will store the graph.
2. Enter how many nodes you want in a graph.
3. Enter the edges of the graph by two vertices each, say Vi , Vj indicates some edge
4. If the graph is directed set M[i][j]=1. If graph is undirected set M[i][j] =1 and M[j][i] =1
as well.
5. When all the edges of the desired graph is entered print the graph M[i][j].

Graph creation using Adjacency list
1. Declare node structure for creating adjacency list.
2. Initialize an array of nodes. This array will act as head nodes. The index of head[ ] will
be the starting vertex.
3. The create function will create the adjacency list.

*/


#include<iostream>
using namespace std;
#define MAX 10
int unidirection;
int way;
static int visited[MAX];
int DFSM(int i, int adjMatrix[][MAX])
{
    visited[i] = 1;
    for(int j=0; j<MAX; j++)
    {
        if(adjMatrix[i][j]==0)
        {
            return 0;
        }
        else if((adjMatrix[i][j] != 0) && (visited[j] == 0))
        {
            DFSM(j, adjMatrix);
        }
    }
    return 1;  
}
struct Node
{
    int destination;
    int weight;
    struct Node *next;
}*head, *temp;
int insert(Node *cities[])
{  
    int src, dest, w;
    Node *ptr = new Node();
    cout<<"\nNew Flight:\nSource : ";
    cin>>src;
    cout<<"Destination : ";
    cin>>dest;
    cout<<"Time required : ";
    cin>>w;
    ptr->destination = dest;
    ptr->weight = w;
    ptr->next = NULL;
    if(cities[src-1]==NULL)
    {
        cities[src-1] = ptr;
    }
    else
    {
        temp = cities[src-1];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    if(unidirection==0)
    {
        Node *ptr = new Node();
        ptr->destination = src;
        ptr->weight = w;
        ptr->next = NULL;
        if(cities[dest-1]==NULL)
        {
            cities[dest-1] = ptr;
        }
        else
        {
            temp = cities[dest-1];
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    return 1;
}
int display(Node *cities[])
{
    cout<<"\n##### Flight Schedule ##### ";
    for(int i=0; i<MAX; i++)
    {
        if(cities[i]!=NULL)
        {
            cout<<"\nCity "<<i+1<<" :\n";
            for(temp = cities[i]; temp!=NULL; temp = temp->next)
            {
                cout<<"\tTo : City "<<temp->destination<<", (Weight : "<<temp->weight<<")\n";
            }
        }
    }
    cout<<"\n########################\n";
    return 1;
}
int *DFS(Node *cities[] ,int i, int visited[])
{
    visited[i] = 1;
    for(temp = cities[i]; temp!=NULL; temp = temp->next)
    {
        if(visited[temp->destination]==0)
        {
            cout<<*visited;
            DFS(cities, i+1, visited);
        }
    }
    int *ptr;
    ptr = &visited[0];
    return ptr;
}
void checkcity(Node *cities[], int visited[])
{
    int i = 0;
    int *ptr = DFS(cities ,i, visited);
    for(int j=0; j<MAX; j++)
    {
        cout<<"City "<<j<<*ptr;
        ptr++;
    }
}
int main()
{
    int choice;
    int no;
    cout<<"Press\n1. Adjecency Matrix\n2. Adjecency List\n-->";
    cin>>way;
    cout<<"Press\n1. Unidirectional\n2. Bi-directional\n-->";
    cin>>choice;
    if(choice == 1)
    {
        unidirection = 1;
    }
    else
    {
        unidirection = 0;
    }
    if(way == 1)
    {   
        int src, dest, w;
        int adjMatrix[MAX][MAX];
        for(int i=0; i<MAX; i++)
        {
            for(int j=0; j<MAX; j++)
            {
                adjMatrix[i][j]=0;
            }
        }
        while(1)
        {
            cout<<"Enter choice :\n1. New flight\n2. Display\n3. Check whether a cities is disconnected\n4. Exit\n-->";
            cin>>choice;
            switch(choice)
            {
                case 1 :    cout<<"From city : ";
                            cin>>src;
                            cout<<"To city : ";
                            cin>>dest;
                            cout<<"Weight of flight : ";
                            cin>>w;
                            adjMatrix[src-1][dest-1] = w;
                            if(unidirection==0)
                            {
                                adjMatrix[dest-1][src-1] = w;
                            }
                            break;
                case 2 :    for(int i=0; i<MAX; i++)
                            {
                                for(int j=0; j<MAX; j++)
                                {
                                    cout<<" "<<adjMatrix[i][j];
                                }
                                cout<<"\n";
                            }
                            break;
                case 3 :    
                            for(int v=0; v<MAX; v++)
                            {
                                visited[v]=0;
                            }
                            int k;
                            k=0;
                            k = DFSM(k, adjMatrix);
                            if(k ? cout<<"Graph is connected!" : cout<<"Graph is disconnected!")
                            for(int k = 0; k<MAX; k++)
                            {
                                cout<<" "<<visited[k];
                            }
                default:    exit(1);
                            break;
            }
        }
    }
    else if(way == 2)
    {
        Node *cities[MAX];
        for(int i=0;i<=MAX;i++)
        { 
            cities[i] = NULL; 
        }
        while(1)
        {
            cout<<"Enter choice :\n1. New flight\n2. Display\n3. Check whether a cities is disconnected\n4. Exit\n-->";
            cin>>choice;
            switch(choice)
            {
                case 1 :    insert(cities);
                            break;
                case 2 :    display(cities);
                            break;
                case 3 :    int visited[MAX];
                            int v;
                            for(v=0;v<MAX;v++);
                            {
                                visited[v] = 0;
                            }
                            checkcity(cities, visited);
                            break;
                default:    exit(1);
                            break;
            }
        }
    }
}