#include <iostream>
using namespace std;

#define MAX 100

struct PriorityQueue {
    int arr[MAX];
    int size;
};

// Initialize queue
void init(PriorityQueue &pq) {
    pq.size = 0;
}

// Helper function to swap
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Insert element in Max-Heap
void insert(PriorityQueue &pq, int value) {
    if (pq.size >= MAX) {
        cout << "Queue overflow!" << endl;
        return;
    }

    pq.arr[pq.size] = value;
    int i = pq.size;
    pq.size++;

    // Fix the heap property
    while (i > 0 && pq.arr[(i - 1) / 2] < pq.arr[i]) {
        swap(pq.arr[i], pq.arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract highest priority (maximum)
int extractMax(PriorityQueue &pq) {
    if (pq.size <= 0) {
        cout << "Queue underflow!" << endl;
        return -1;
    }
    int root = pq.arr[0];
    pq.arr[0] = pq.arr[pq.size - 1];
    pq.size--;

    // Heapify down
    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < pq.size && pq.arr[left] > pq.arr[largest])
            largest = left;
        if (right < pq.size && pq.arr[right] > pq.arr[largest])
            largest = right;

        if (largest == i)
            break;

        swap(pq.arr[i], pq.arr[largest]);
        i = largest;
    }
    return root;
}

// Display queue elements
void display(PriorityQueue pq) {
    cout << "Priority Queue: ";
    for (int i = 0; i < pq.size; i++)
        cout << pq.arr[i] << " ";
    cout << endl;
}

int main() {
    PriorityQueue pq;
    init(pq);

    insert(pq, 10);
    insert(pq, 40);
    insert(pq, 30);
    insert(pq, 20);
    insert(pq, 50);

    display(pq);

    cout << "Extracted Max: " << extractMax(pq) << endl;
    display(pq);

    return 0;
}
