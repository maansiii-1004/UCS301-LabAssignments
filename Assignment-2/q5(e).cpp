#include <iostream>
using namespace std;

int symmetricM[5050];
int n;

void setSymmetric(int i, int j, int val) {
    if(i >= j)
        symmetricM[(i*(i-1))/2 + (j-1)] = val;
    else
        symmetricM[(j*(j-1))/2 + (i-1)] = val;
}

int getSymmetric(int i, int j) {
    if(i >= j)
        return symmetricM[(i*(i-1))/2 + (j-1)];
    else
        return symmetricM[(j*(j-1))/2 + (i-1)];
}

void displaySymmetric() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << getSymmetric(i,j) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    for(int i=0; i<(n*(n+1))/2; i++) symmetricM[i] = 0;

    cout << "Enter elements row-wise:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int val;
            cin >> val;
            setSymmetric(i,j,val);
        }
    }

    cout << "Symmetric Matrix:\n";
    displaySymmetric();

    return 0;
}
