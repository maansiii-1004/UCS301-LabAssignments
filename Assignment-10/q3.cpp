#include <iostream>
using namespace std;

class HashMap {
    static const int SIZE = 20;
    int keys[SIZE];
    int values[SIZE];

public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            keys[i] = -1;   // empty key
            values[i] = 0;  // freq
        }
    }

    void insert(int key) {
        int index = abs(key) % SIZE;

        while (keys[index] != -1 && keys[index] != key)
            index = (index + 1) % SIZE;

        if (keys[index] == -1) {
            keys[index] = key;
            values[index] = 1;
        } else {
            values[index]++; // increase frequency
        }
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (keys[i] != -1)
                cout << keys[i] << " → " << values[i] << " times\n";
        }
    }
};

int main() {
    int nums[] = {2, 3, 2, 4, 3, 2};
    int n = 6;

    HashMap mp;

    for (int i = 0; i < n; i++)
        mp.insert(nums[i]);

    mp.display();
}
