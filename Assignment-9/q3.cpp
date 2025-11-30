#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

Edge edges[50];
int parent[20];

int findParent(int x) {
    while(parent[x] != x)
        x = parent[x];
    return x;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v w):\n";
    for(int i=0; i<e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // initialize parent
    for(int i=0; i<n; i++)
        parent[i] = i;

    // simple bubble sort edges by weight
    for(int i=0;i<e;i++)
        for(int j=i+1;j<e;j++)
            if(edges[i].w > edges[j].w)
                swap(edges[i], edges[j]);

    cout << "Kruskal MST:\n";
    int count = 0;

    for(int i=0; i<e && count<n-1; i++) {
        int pu = findParent(edges[i].u);
        int pv = findParent(edges[i].v);

        if(pu != pv) {
            cout << edges[i].u << " - " << edges[i].v << "  (" << edges[i].w << ")\n";
            parent[pv] = pu;
            count++;
        }
    }

    return 0;
}
