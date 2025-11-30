#include <iostream>
using namespace std;

int tridiagonal[300];
int n;

void setTriDiagonal(int i, int j, int val) {
    if(i - j == 1)           // Lower diagonal
        tridiagonal[i-2] = val;
    else if(i - j == 0)      // Main diagonal
        tridiagonal[n - 1 + i - 1] = val;
    else if(i - j == -1)     // Upper diagonal
        tridiagonal[2*n - 1 + i - 1] = val;
}

int getTriDiagonal(int i, int j) {
    if(i - j == 1)
        return tridiagonal[i-2];
    else if(i - j == 0)
        return tridiagonal[n - 1 + i - 1];
    else if(i - j == -1)
        return tridiagonal[2*n - 1 + i - 1];
    return 0;
}

void displayTriDiagonal() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getTriDiagonal(i,j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    for(int i=0; i<3*n-2; i++) tridiagonal[i] = 0;

    cout << "Enter elements row-wise (only main diagonal and 1 above/below will be stored):\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int val;
            cin >> val;
            setTriDiagonal(i,j,val);
        }
    }

    cout << "Tri-diagonal Matrix:\n";
    displayTriDiagonal();

    return 0;
}
