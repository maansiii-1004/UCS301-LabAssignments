#include <iostream>
#include <queue>
using namespace std;

class StackUsingSingleQueue {
    queue<int> q;

public:
   
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue to move the new element to front
        for (int i = 0; i < size; i++) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }

  
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

   
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

   
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingSingleQueue s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; 

    s.pop(); 
    cout << "Top element after pop: " << s.top() << endl; 

    s.pop(); 
    s.pop(); 

    s.pop(); 

    return 0;
}
