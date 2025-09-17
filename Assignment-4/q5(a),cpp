#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
    queue<int> q1, q2;

public:
    
    void push(int x) {
        
        if (q1.empty()) {
            q1.push(x);
            // Move all elements from q2 to q1
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q2.push(x);
            // Move all elements from q1 to q2
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

   
    void pop() {
        if (!q1.empty()) {
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
        } else if (!q2.empty()) {
            cout << "Popped: " << q2.front() << endl;
            q2.pop();
        } else {
            cout << "Stack is empty\n";
        }
    }

   
    int top() {
        if (!q1.empty()) return q1.front();
        else if (!q2.empty()) return q2.front();
        else {
            cout << "Stack is empty\n";
            return -1;
        }
    }

   
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
    StackUsingQueues s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop(); // Pops 30
    cout << "Top element after pop: " << s.top() << endl; 

    s.pop(); 
    s.pop(); 

    s.pop(); 

    return 0;
}
