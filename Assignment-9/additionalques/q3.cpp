#include <iostream>
using namespace std;

const int MAXN = 100;
const int MAXE = 200;
const int INF = 1e9;

struct Edge {
    int v, w;
    int next;
};

Edge edges[MAXE];
int head[MAXN];
int edgeCount = 0;

int distArr[MAXN];
int visited[MAXN];

// Add directed edge u -> v with weight w
void addEdge(int u, int v, int w) {
    edges[edgeCount].v = v;
    edges[edgeCount].w = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount;
    edgeCount++;
}

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    // initialize head[]
    for (int i = 1; i <= N; i++) {
        head[i] = -1;
        distArr[i] = INF;
        visited[i] = 0;
    }

    edgeCount = 0;

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    // Dijkstra start
    distArr[K] = 0;

    for (int step = 0; step < N; step++) {

        // Find unvisited node with minimum dist
        int minDist = INF, u = -1;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && distArr[i] < minDist) {
                minDist = distArr[i];
                u = i;
            }
        }

        if (u == -1) break;  // no more reachable nodes

        visited[u] = 1;

        // Relax edges from u
        int idx = head[u];
        while (idx != -1) {
            int v = edges[idx].v;
            int w = edges[idx].w;

            if (distArr[u] + w < distArr[v]) {
                distArr[v] = distArr[u] + w;
            }

            idx = edges[idx].next;
        }
    }

    // Find maximum distance
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (distArr[i] == INF) {
            cout << -1;
            return 0;
        }
        if (distArr[i] > ans)
            ans = distArr[i];
    }

    cout << ans;
    return 0;
}

