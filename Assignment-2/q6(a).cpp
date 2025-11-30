#include <iostream>
using namespace std;

const int MAX = 100;

void transposeSparse(int original[MAX][3], int transposed[MAX][3]) {
    int rows = original[0][0];
    int cols = original[0][1];
    int nonZero = original[0][2];

    transposed[0][0] = cols;
    transposed[0][1] = rows;
    transposed[0][2] = nonZero;

    int k = 1;
    for(int col=0; col<cols; col++) {
        for(int i=1; i<=nonZero; i++) {
            if(original[i][1] == col) {
                transposed[k][0] = original[i][1];
                transposed[k][1] = original[i][0];
                transposed[k][2] = original[i][2];
                k++;
            }
        }
    }
}

void printSparse(int matrix[MAX][3]) {
    int total = matrix[0][2];
    cout << "Row Col Val\n";
    for(int i=0; i<=total; i++) {
        cout << matrix[i][0] << "   " << matrix[i][1] << "   " << matrix[i][2] << "\n";
    }
}

int main() {
    int A[MAX][3], T[MAX][3];
    int r, c, val, k = 1;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter non-zero elements in format (row col value), end with -1 -1 -1:\n";
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

    cout << "\nOriginal Matrix (Triplet Form):\n";
    printSparse(A);

    transposeSparse(A, T);

    cout << "\nTransposed Matrix (Triplet Form):\n";
    printSparse(T);

    return 0;
}
