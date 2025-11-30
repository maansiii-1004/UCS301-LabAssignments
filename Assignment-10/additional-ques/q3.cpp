#include <iostream>
using namespace std;

// Manual Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to check if arrays are equal
bool areArraysEqual(int a[], int b[], int n) {
    bubbleSort(a, n);
    bubbleSort(b, n);

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int main() {
    int a1[] = {1, 2, 5, 4, 0};
    int b1[] = {2, 4, 5, 0, 1};
    int n1 = 5;

    cout << (areArraysEqual(a1, b1, n1) ? "true" : "false") << endl;

    int a2[] = {1, 2, 5, 4, 0, 2, 1};
    int b2[] = {2, 4, 5, 0, 1, 1, 2};
    int n2 = 7;

    cout << (areArraysEqual(a2, b2, n2) ? "true" : "false") << endl;

    int a3[] = {1, 7, 1};
    int b3[] = {7, 7, 1};
    int n3 = 3;

    cout << (areArraysEqual(a3, b3, n3) ? "true" : "false") << endl;

    return 0;
}
