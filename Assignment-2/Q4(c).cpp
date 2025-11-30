#include <iostream>
using namespace std;

bool isVowel(char ch) {
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin >> str;

    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';

    cout << "String after removing vowels: " << result << "\n";
    return 0;
}
