#include <bits/stdc++.h>
using namespace std;

string checkAnagram(string str1, string str2) {
    // If lengths are different, they can't be anagrams
    if (str1.length() != str2.length()) {
        return "NO";
    }
    
    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    // Compare sorted strings
    if (str1 == str2) {
        return "YES";
    }
    return "NO";
}

int main() {
    
        string str1, str2;
        cout<<"enter two strings"<<endl;
        cin >> str1 >> str2;
        cout << checkAnagram(str1, str2) << endl;
    
    
    return 0;
}