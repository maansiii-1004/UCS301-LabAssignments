#include <iostream>
using namespace std;

const int INF = 1e9;
const int MAX = 100;   


int grid[MAX][MAX];

int dist[MAX][MAX];


int visited[MAX][MAX];

int main() {
    int m, n;
    cin >> m >> n;

  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            dist[i][j] = INF;
            visited[i][j] = 0;
        }
    }

    
    dist[0][0] = grid[0][0];

    // Dijkstra on grid
    for (int step = 0; step < m * n; step++) {

        // 1) Find unvisited cell with minimum dist[][]  
        int minDist = INF, x = -1, y = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && dist[i][j] < minDist) {
                    minDist = dist[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        // Mark it visited
        visited[x][y] = 1;

        // 2) Relax all 4 possible neighbors
        // up, down, left, right
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Check bounds
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newCost = dist[x][y] + grid[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                }
            }
        }
    }

    // Final answer
    cout << dist[m-1][n-1];

    return 0;
}
