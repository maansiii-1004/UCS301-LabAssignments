#include <iostream>
using namespace std;

int lower[5050];
int n;

void setLower(int i, int j, int val) {
    if(i >= j)
        lower[(i*(i-1))/2 + (j-1)] = val;
}

int getLower(int i, int j) {
    if(i >= j)
        return lower[(i*(i-1))/2 + (j-1)];
    return 0;
}

void displayLower() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getLower(i,j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    for(int i=0; i<(n*(n+1))/2; i++) lower[i] = 0;

    cout << "Enter elements row-wise:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int val;
            cin >> val;
            setLower(i,j,val);
        }
    }

    cout << "Lower Triangular Matrix:\n";
    displayLower();

    return 0;
}
