#include <iostream>
using namespace std;

class HashMap {
    static const int SIZE = 50;
    int keys[SIZE];
    int freq[SIZE];

public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            keys[i] = -1;
            freq[i] = 0;
        }
    }

    void insert(int key) {
        int index = abs(key) % SIZE;

        while (keys[index] != -1 && keys[index] != key)
            index = (index + 1) % SIZE;

        if (keys[index] == -1) {
            keys[index] = key;
            freq[index] = 1;
        } else {
            freq[index]++;
        }
    }

    int getFreq(int key) {
        int index = abs(key) % SIZE;
        int start = index;

        while (keys[index] != -1) {
            if (keys[index] == key)
                return freq[index];

            index = (index + 1) % SIZE;
            if (index == start) break;
        }
        return 0;
    }
};

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = 6;

    HashMap map;

    // count frequency
    for (int i = 0; i < n; i++)
        map.insert(arr[i]);

    // find first non-repeating
    for (int i = 0; i < n; i++) {
        if (map.getFreq(arr[i]) == 1) {
            cout << arr[i];
            return 0;
        }
    }

    cout << "No non-repeating element";
}
