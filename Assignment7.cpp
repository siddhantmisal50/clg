/*
You have a business with several offices; you want to lease phone lines to
connect them up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices with a
minimum total cost. Solve the problem by suggesting appropriate data structures

Algortithm:
Prim’s Algorithm:
MST= {0} // start with vertex 0
For (T=0; T contains fewer than n-1 edges; add(u,v) to T)
{
Let (u,v) be a least cost edge such that u є TV & v not belonging to TV;
Add V to TV
}

*/
#include <iostream>
#define MAX 20
#define INFINITY 999
using namespace std;
class graph
{
public:
    int vertices, edges, weight, u, v;
    int visited[MAX];
    int cost = 0;
    void read()
    {
        int GMAT[20][20];
        cout << "Enter the number of vertices : ";
        cin >> vertices;
        cout << "Enter the number of edges : ";
        cin >> edges;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                GMAT[i][j] = 0;
            }
        }
        cout << "Enter the source vertex, destination vertex and weight\n";
        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v >> weight;
            GMAT[u - 1][v - 1] = weight;
            GMAT[v - 1][u - 1] = weight;
        }
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << GMAT[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }
        cout << "\n\nMatrix :\n";
        for (int i = 0; i < vertices - 1; i++)
        {
            int min = 99999;
            for (int j = 0; j < vertices; j++)
            {
                if (GMAT[i][j] != 0 && GMAT[i][j] < min && visited[i] == 0)
                {
                    min = GMAT[i][j];
                    u = i;
                    v = j;
                }
            }
            visited[u] = 1;
            cout << u + 1 << " " << v + 1 << " " << min << "\n";
            cost = cost + min;
        }
        cout << endl;
        cout << "Minimum cost :" << cost;
    }
};
int main()
{
    graph g;
    g.read();
    return 0;
}