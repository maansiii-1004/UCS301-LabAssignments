#include <iostream>
using namespace std;

class HashSet {
    static const int SIZE = 20;
    int table[SIZE];

public:
    HashSet() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key) {
        int index = abs(key) % SIZE;

        while (table[index] != -1 && table[index] != key)
            index = (index + 1) % SIZE;

        table[index] = key;
    }

    bool contains(int key) {
        int index = abs(key) % SIZE;
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            index = (index + 1) % SIZE;

            if (index == start) break;
        }
        return false;
    }
};

int main() {
    int A[] = {1, 2, 3, 4};
    int B[] = {3, 4, 5, 6};

    HashSet hs;

    for (int x : A)
        hs.insert(x);

    for (int x : B)
        if (hs.contains(x))
            cout << x << " ";

    return 0;
}
