#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size should be even for interleaving."<<endl;
        return;
    }

    int half = n / 2;
    int firstHalf[half];

   
    for (int i = 0; i < half; i++) {
        firstHalf[i] = q.dequeue();
    }

    //  Interleave by enqueueing elements from first half and the remaining queue
    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf[i]);  // first half element
        q.enqueue(q.dequeue());   // second half element from queue
    }
}

int main() {
    Queue q;

    
    int elements[] = {4, 7, 11, 20, 5, 9};
   int n=6;

    for (int i = 0; i < n; i++) {
        q.enqueue(elements[i]);
    }

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
