#include <iostream>
using namespace std;

int upper[5050];
int n;

void setUpper(int i, int j, int val) {
    if(i <= j)
        upper[(j*(j-1))/2 + (i-1)] = val;
}

int getUpper(int i, int j) {
    if(i <= j)
        return upper[(j*(j-1))/2 + (i-1)];
    return 0;
}

void displayUpper() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getUpper(i,j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    for(int i=0; i<(n*(n+1))/2; i++) upper[i] = 0;

    cout << "Enter elements row-wise:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int val;
            cin >> val;
            setUpper(i,j,val);
        }
    }

    cout << "Upper Triangular Matrix:\n";
    displayUpper();

    return 0;
}
