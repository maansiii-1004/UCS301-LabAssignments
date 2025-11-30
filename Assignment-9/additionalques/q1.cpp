#include <iostream>
using namespace std;

struct Edge {
    int v;
    int next;
};

const int MAXV = 1000;      // max vertices
const int MAXE = 2000;      // max edges (undirected → 2E)

Edge edges[MAXE];
int head[MAXV];
int edgeCount = 0;
int visited[MAXV];

void addEdge(int u, int v) {
    edges[edgeCount].v = v;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount;
    edgeCount++;
}


int Q[MAXV];
int frontQ, rearQ;

// BFS from a start node
void bfs(int start) {
    frontQ = rearQ = 0;

    Q[rearQ++] = start;
    visited[start] = 1;

    while (frontQ < rearQ) {
        int u = Q[frontQ++];
        
        // traverse adjacency list
        int i = head[u];
        while (i != -1) {
            int v = edges[i].v;
            if (!visited[v]) {
                visited[v] = 1;
                Q[rearQ++] = v;
            }
            i = edges[i].next;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    // initialize head array
    for (int i = 0; i < V; i++) {
        head[i] = -1;
        visited[i] = 0;
    }

    edgeCount = 0;

    // input edges (undirected)
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int components = 0;

    // count connected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfs(i);
            components++;
        }
    }

    cout << components;
    return 0;
}
