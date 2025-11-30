#include <iostream>
using namespace std;

class HashMap {
    static const int SIZE = 50;
    int keys[SIZE];
    int freq[SIZE];

public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            keys[i] = -1;   // empty
            freq[i] = 0;
        }
    }

    void insert(int key) {
        int index = abs(key) % SIZE;

        // linear probing
        while (keys[index] != -1 && keys[index] != key)
            index = (index + 1) % SIZE;

        if (keys[index] == -1) {
            keys[index] = key;
            freq[index] = 1;
        } else {
            freq[index]++;
        }
    }

    // find element with highest frequency
    int getMostFrequent() {
        int maxFreq = 0;
        int answer = -1;

        for (int i = 0; i < SIZE; i++) {
            if (keys[i] != -1) {
                if (freq[i] > maxFreq) {
                    maxFreq = freq[i];
                    answer = keys[i];
                }
                else if (freq[i] == maxFreq && keys[i] > answer) {
                    answer = keys[i]; // tie → choose larger value
                }
            }
        }
        return answer;
    }
};

int main() {
    int arr[] = {1, 2, 2, 4, 1};
    int n = 5;

    HashMap hm;

    for (int i = 0; i < n; i++)
        hm.insert(arr[i]);

    cout << hm.getMostFrequent();
