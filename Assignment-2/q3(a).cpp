#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    // If no mismatch, then last number is missing
    return n;
}

int main() {
    int arr[100], n;

    cout << "Enter the value of n  "<<endl;
    cin >> n;

    cout << "Enter " << n - 1 << " elements"<<endl;
    for (int i = 0; i < n - 1; ++i) {
        cin >> arr[i];
    }

    int missing = findMissingNumber(arr, n);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
