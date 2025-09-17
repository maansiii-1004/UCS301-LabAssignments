#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeatingChar(string str) {
    queue<char> q;
    int freq[26]={0};

    for (char ch : str) {
     
        freq[ch]++;
        q.push(ch);

        // Remove characters from front if repeated
        while (!q.empty() && freq[q.front()-'a'] > 1) {
            q.pop();
        }

        // Print first non-repeating or -1
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
}

int main() {
    string s;
    cin>>s;
    cout << "Input string: " << s << endl;
    cout << "First non-repeating characters: ";
    firstNonRepeatingChar(s);
    return 0;
}
