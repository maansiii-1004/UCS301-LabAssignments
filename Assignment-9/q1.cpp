#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];
    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    int visited[20] = {0};
    int queue[20];
    int front = 0, rear = 0;

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS: ";

    while(front < rear) {
        int u = queue[front++];
        cout << u << " ";

        for(int v=0; v<n; v++) {
            if(graph[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}
