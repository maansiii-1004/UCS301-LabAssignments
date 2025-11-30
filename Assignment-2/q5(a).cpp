#include <iostream>
using namespace std;

int diagonal[100];
int n;

void setDiagonal(int i, int j, int val) {
    if(i == j)
        diagonal[i-1] = val;
}

int getDiagonal(int i, int j) {
    if(i == j)
        return diagonal[i-1];
    return 0;
}

void displayDiagonal() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getDiagonal(i,j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    // Initialize diagonal elements with 0
    for(int i=0; i<n; i++) diagonal[i] = 0;

    cout << "Enter elements row-wise (only diagonal elements will be stored):\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int val;
            cin >> val;
            setDiagonal(i,j,val);
        }
    }

    cout << "Diagonal Matrix:\n";
    displayDiagonal();

    return 0;
}
