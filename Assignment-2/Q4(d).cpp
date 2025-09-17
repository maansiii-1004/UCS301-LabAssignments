#include <iostream>
#include <cstring>  
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char arr[n][100];  

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {  // If arr[j] > arr[j+1], swap
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
