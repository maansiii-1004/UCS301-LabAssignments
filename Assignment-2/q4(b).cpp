#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int len = 0;
    while (str[len] != '\0') len++;

    
    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << "\n";

    return 0;
}
