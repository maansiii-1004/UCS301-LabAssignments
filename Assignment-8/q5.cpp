#include <iostream>
using namespace std;

// Heapify function to maintain heap property
void heapify(int arr[], int n, int i, bool increasing) {
    int extreme = i; // either largest or smallest
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (increasing) { // max-heap for increasing order
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else { // min-heap for decreasing order
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    
    for (int i = n - 1; i > 0; i--) {
    
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

      
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    bool increasing = true; // true = increasing, false = decreasing
    heapSort(arr, n, increasing);

    cout << "\nSorted array (" << (increasing ? "Increasing" : "Decreasing") << "): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
