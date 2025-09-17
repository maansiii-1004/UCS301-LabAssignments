#include <iostream>
using namespace std;

void nearestSmallerToLeft(int A[], int n, int result[]) {
    int stack[n];    
    int top = -1;    

    for (int i = 0; i < n; i++) {
        
        while (top != -1 && stack[top] >= A[i]) {
            top--;
        }

       
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = stack[top];
        }

        
        stack[++top] = A[i];
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int A[n];      
    int result[n];  

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    nearestSmallerToLeft(A, n, result);

    cout << "Nearest smaller elements to the left are:\n";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
