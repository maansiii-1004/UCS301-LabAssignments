#include <iostream>
using namespace std;

class HashSet {
    static const int SIZE = 20;
    int table[SIZE];

public:
    HashSet() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;   // empty
    }

    bool insert(int key) {
        int index = abs(key) % SIZE;

        while (table[index] != -1) {
            if (table[index] == key)
                return false; // duplicate found
            index = (index + 1) % SIZE; // linear probing
        }

        table[index] = key;
        return true; // inserted
    }
};

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = 4;

    HashSet hs;

    for (int i = 0; i < n; i++) {
        if (!hs.insert(nums[i])) {
            cout << "true"; // duplicate exists
            return 0;
        }
    }

    cout << "false"; // no duplicate
}
