#include <iostream>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void DFS(int u) {
    cout << u << " ";
    visited[u] = 1;

    for(int v=0; v<n; v++) {
        if(graph[u][v] == 1 && visited[v] == 0) {
            DFS(v);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    for(int i=0;i<n;i++)
        visited[i] = 0;

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start);

    return 0;
}
