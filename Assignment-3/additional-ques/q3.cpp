#include <iostream>
using namespace std;

void nextGreaterElement(int arr[], int n, int result[]) {
    int stack[n];  
    int top = -1;


    for (int i = n - 1; i >= 0; i--) {
  
        while (top != -1 && stack[top] <= arr[i]) {
            top--;
        }

       
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = stack[top];
        }

       
        stack[++top] = arr[i];
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result[n];
    nextGreaterElement(arr, n, result);

    cout << "Next Greater Elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
