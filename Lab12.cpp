#include <iostream>
#include <climits>
using namespace std;

#define V 6

int minDistance(int dist[], bool visited[])
{
    int minDist = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && dist[v] <= minDist)
        {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void printSolution(int dist[], int parent[], int src)
{
    cout << "City\tShortest Distance\tShortest Path" << endl;
    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            cout << src << " -> " << i << "\t" << dist[i] << "\t\t" << src;
            printPath(parent, i);
            cout << endl;
        }
    }

    double sum = 0;
    for (int j=0; j< V ;j++){
        sum += dist[j];
    }

    double avg=sum/5;
    cout << "Avarage time for city " << src << " = " << avg ;

    
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];     
    bool visited[V]; 
    int parent[V];  
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0; 

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int source;
    cout << "Enter the source number: ";
    cin >> source;

          // For finding avarage time for each city
    // for (int x=0; x<V;x++){
    //     int source = x ; 
    //     dijkstra(graph, source);
    //     cout << endl;
    // }
    
    return 0;
}
