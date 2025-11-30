#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];
    cout << "Enter cost adjacency matrix (999 for no edge):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    int dist[20], visited[20]={0};

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // initialize dist
    for(int i=0;i<n;i++)
        dist[i] = graph[start][i];

    dist[start] = 0;
    visited[start] = 1;

    for(int k=0;k<n-1;k++) {
        int min = 99999, u = -1;

        // find unvisited with smallest distance
        for(int i=0;i<n;i++)
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        // relax edges
        for(int v=0; v<n; v++) {
            if(!visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Shortest distances:\n";
    for(int i=0;i<n;i++)
        cout << start << " -> " << i << " = " << dist[i] << "\n";

    return 0;
}
