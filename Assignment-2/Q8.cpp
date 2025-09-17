#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int distinctCount = 0;
    
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
       
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            distinctCount++;
        }
    }
    return distinctCount;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];  
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinct = countDistinct(arr, n);
    cout << "Total number of distinct elements: " << distinct << "\n";

    return 0;
}
