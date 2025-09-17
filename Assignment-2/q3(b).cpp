#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] != arr[0] + mid) {
          
            end = mid - 1;
        } else {
            
            start = mid + 1;
        }
    }

    
    return arr[0] + start;
}

int main() {
    int n;
    cout << "Enter number of elements in array (excluding the missing number): ";
    cin >> n;
    n = n + 1; 
    int arr[n-1];
    cout << "Enter " << n-1 << " sorted numbers of the array:\n";
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    int missing = findMissing(arr, n-1);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
