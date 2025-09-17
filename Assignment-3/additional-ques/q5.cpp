#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
               
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

bool canSortUsingStack(int A[], int n) {
    int sortedA[n];
  
    for (int i = 0; i < n; i++) {
        sortedA[i] = A[i];
    }

   
    bubbleSort(sortedA, n);

    int stack[n];    
    int top = -1;    

    int idx = 0;  

    for (int i = 0; i < n; i++) {
       
        stack[++top] = A[i];

       
        while (top != -1 && stack[top] == sortedA[idx]) {
            top--;   
            idx++;    
        }
    }

   
    while (top != -1 && stack[top] == sortedA[idx]) {
        top--;
        idx++;
    }

   
    return (idx == n);
}

int main() {
    int n;
    cout << "Enter size of array A: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of array A:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    if (canSortUsingStack(A, n)) {
        cout << " it is possible to sort array B using the stack operations.\n";
    } else {
        cout << " it is NOT possible to sort array B using the stack operations.\n";
    }

    return 0;
}
