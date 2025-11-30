#include <iostream>
using namespace std;

const int MAX = 100;

int grid[MAX][MAX];
int visited[MAX][MAX];

int main() {
    int M, N;
    cin >> M >> N;

    // Input grid (0/1)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }

    int islands = 0;

    // Manual stack for DFS (array-based)
    int stackX[MAX * MAX];
    int stackY[MAX * MAX];
    int top;

    // Directions: right, left, down, up
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            if (grid[i][j] == 1 && !visited[i][j]) {

                islands++;

                // Start DFS
                top = 0;
                stackX[top] = i;
                stackY[top] = j;
                visited[i][j] = 1;

                // Process stack
                while (top >= 0) {

                    int x = stackX[top];
                    int y = stackY[top];
                    top--;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
                            if (grid[nx][ny] == 1 && !visited[nx][ny]) {

                                visited[nx][ny] = 1;
                                top++;
                                stackX[top] = nx;
                                stackY[top] = ny;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << islands;
    return 0;
}
