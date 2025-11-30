#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        // Find both minimum and maximum in the current unsorted part
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum with the first element
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;

        // If max element was at the start position, it got moved when swapping min
        if (maxIndex == start)
            maxIndex = minIndex;

        // Swap maximum with the last element
        temp = arr[end];
        arr[end] = arr[maxIndex];
        arr[maxIndex] = temp;

        // Move boundaries inward
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
