#include <iostream>
using namespace std;

const int MAX = 100;

void transpose(int B[MAX][3], int BT[MAX][3]) {
    int n = B[0][2];
    BT[0][0] = B[0][1];
    BT[0][1] = B[0][0];
    BT[0][2] = n;

    int k = 1;
    for(int col = 0; col < B[0][1]; col++) {
        for(int i = 1; i <= n; i++) {
            if(B[i][1] == col) {
                BT[k][0] = B[i][1];
                BT[k][1] = B[i][0];
                BT[k][2] = B[i][2];
                k++;
            }
        }
    }
}

void multiply(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible due to dimension mismatch.\n";
        return;
    }

    int BT[MAX][3];
    transpose(B, BT);

    result[0][0] = A[0][0];
    result[0][1] = B[0][1];
    int k = 1;

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= BT[0][2]; j++) {
            if (A[i][1] == BT[j][1]) {
                int r = A[i][0];
                int c = BT[j][0];
                int val = A[i][2] * BT[j][2];

                bool found = false;
                for (int x = 1; x < k; x++) {
                    if (result[x][0] == r && result[x][1] == c) {
                        result[x][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result[k][0] = r;
                    result[k][1] = c;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }
    result[0][2] = k - 1;
}

void printSparse(int matrix[MAX][3]) {
    int total = matrix[0][2];
    cout << "Row Col Val\n";
    for(int i = 0; i <= total; i++) {
        cout << matrix[i][0] << "   " << matrix[i][1] << "   " << matrix[i][2] << "\n";
    }
}

int main() {
    int A[MAX][3], B[MAX][3], PROD[MAX][3];
    int r1, c1, r2, c2, val, k;

    // Input Matrix A
    cout << "Enter number of rows and columns of Matrix A: ";
    cin >> r1 >> c1;

    k = 1;
    cout << "Enter non-zero elements for Matrix A in format (row col value), enter -1 -1 -1 to end:\n";
    while(true) {
        int i, j;
        cin >> i >> j >> val;
        if(i == -1 && j == -1 && val == -1) break;
        A[k][0] = i;
        A[k][1] = j;
        A[k][2] = val;
        k++;
    }
    A[0][0] = r1;
    A[0][1] = c1;
    A[0][2] = k - 1;

    // Input Matrix B
    cout << "Enter number of rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible due to incompatible dimensions.\n";
        return 0;
    }

    k = 1;
    cout << "Enter non-zero elements for Matrix B in format (row col value), enter -1 -1 -1 to end:\n";
    while(true) {
        int i, j;
        cin >> i >> j >> val;
        if(i == -1 && j == -1 && val == -1) break;
        B[k][0] = i;
        B[k][1] = j;
        B[k][2] = val;
        k++;
    }
    B[0][0] = r2;
    B[0][1] = c2;
    B[0][2] = k - 1;

    multiply(A, B, PROD);

    cout << "\nResultant Matrix After Multiplication (Triplet Form):\n";
    printSparse(PROD);

    return 0;
}

