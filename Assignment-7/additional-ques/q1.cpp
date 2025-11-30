#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    // Step 1: Find the maximum and minimum elements
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;

    // Step 2: Create and initialize count array
    int* count = new int[range];
    for (int i = 0; i < range; i++)
        count[i] = 0;

    // Step 3: Count frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    // Step 4: Convert count to cumulative count
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Step 5: Create output array
    int* output = new int[n];

    // Step 6: Place elements in correct position (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Step 7: Copy sorted array back to original
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] count;
    delete[] output;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
