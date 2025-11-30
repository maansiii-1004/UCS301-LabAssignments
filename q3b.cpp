#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[20][20];
    cout << "Enter cost adjacency matrix (0 for no edge):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    int selected[20] = {0};
    selected[0] = 1;

    cout << "Prim MST:\n";

    for(int edges = 0; edges < n-1; edges++) {
        int u = -1, v = -1, min = 99999;

        for(int i = 0; i < n; i++) {
            if(selected[i] == 1) {
                for(int j = 0; j < n; j++) {
                    if(selected[j] == 0 && graph[i][j] != 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << "  (" << min << ")\n";
        selected[v] = 1;
    }

    return 0;
}
