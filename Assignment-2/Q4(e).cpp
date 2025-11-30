#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
        cout << "Lowercase: " << ch << "\n";
    } else {
        cout << "Not an uppercase letter.\n";
    }

    return 0;
}




