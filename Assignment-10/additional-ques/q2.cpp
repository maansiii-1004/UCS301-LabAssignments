#include <iostream>
using namespace std;

// Function to sort the array manually (Bubble Sort)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to check pair sum without using STL
bool hasPairWithSum(int arr[], int n, int target) {
    bubbleSort(arr, n); // Sort first

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;     // need a larger sum
        else
            right--;    // need a smaller sum
    }

    return false;
}

int main() {
    int arr1[] = {0, -1, 2, -3, 1};
    int n1 = 5;
    int target1 = -2;

    if (hasPairWithSum(arr1, n1, target1))
        cout << "true\n";
    else
        cout << "false\n";

    int arr2[] = {1, -2, 1, 0, 5};
    int n2 = 5;
    int target2 = 0;

    if (hasPairWithSum(arr2, n2, target2))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
