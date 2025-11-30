#include <iostream>
using namespace std;

void dailyTemperatures(int temperatures[], int n, int answer[]) {
    int stack[n];
    int top = -1; 

    for (int i = 0; i < n; i++) {
        answer[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];  
            answer[idx] = i - idx;   
        }
    
        stack[++top] = i;
    }
    
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[n];
    cout << "Enter temperatures:";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    int answer[n];

    dailyTemperatures(temperatures, n, answer);

    cout << "Days to wait for a warmer temperature:\n";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}
