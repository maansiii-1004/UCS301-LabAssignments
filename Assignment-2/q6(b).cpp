#include <iostream>
using namespace std;

const int MAX = 100;

void addSparse(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {
    if(A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible.\n";
        return;
    }

    result[0][0] = A[0][0];
    result[0][1] = A[0][1];

    int i=1, j=1, k=1;
    while(i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++;
        }
        else {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++; j++;
        }
        k++;
    }

    while(i <= A[0][2]) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }

    while(j <= B[0][2]) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
}

void printSparse(int matrix[MAX][3]) {
    int total = matrix[0][2];
    cout << "Row Col Val\n";
    for(int i=0; i<=total; i++) {
        cout << matrix[i][0] << "   " << matrix[i][1] << "   " << matrix[i][2] << "\n";
    }
}

int main() {
    int A[MAX][3], B[MAX][3], SUM[MAX][3];
    int r, c, val, k;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    // Matrix A
    k = 1;
    cout << "Enter non-zero elements for Matrix A (-1 -1 -1 to end):\n";
    while (true) {
        int i, j;
        cin >> i >> j >> val;
        if(i == -1 && j == -1 && val == -1) break;
        A[k][0] = i;
        A[k][1] = j;
        A[k][2] = val;
        k++;
    }
    A[0][0] = r;
    A[0][1] = c;
    A[0][2] = k - 1;

    // Matrix B
    k = 1;
    cout << "Enter non-zero elements for Matrix B (-1 -1 -1 to end):\n";
    while (true) {
        int i, j;
        cin >> i >> j >> val;
        if(i == -1 && j == -1 && val == -1) break;
        B[k][0] = i;
        B[k][1] = j;
        B[k][2] = val;
        k++;
    }
    B[0][0] = r;
    B[0][1] = c;
    B[0][2] = k - 1;

    addSparse(A, B, SUM);

    cout << "\nResultant Matrix After Addition (Triplet Form):\n";
    printSparse(SUM);

    return 0;
}
