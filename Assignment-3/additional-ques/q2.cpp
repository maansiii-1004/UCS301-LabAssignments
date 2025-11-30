#include <iostream>
using namespace std;

class MinStack {
    int stack[1000];  
    int topIndex;
    int minEle;

public:
    MinStack() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    void push(int x) {
        if (empty()) {
            topIndex++;
            stack[topIndex] = x;
            minEle = x;
        } else if (x >= minEle) {
            topIndex++;
            stack[topIndex] = x;
        } else {
          
            int encoded = 2 * x - minEle;
            topIndex++;
            stack[topIndex] = encoded;
            minEle = x;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Stack is empty\n";
            return;
        }

        int topVal = stack[topIndex];

        if (topVal < minEle) {
           
            minEle = 2 * minEle - topVal;
        }
        topIndex--;
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        int topVal = stack[topIndex];
        if (topVal < minEle) {
            return minEle;  
        }
        return topVal;
    }

    int getMin() {
        if (empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minEle;
    }
};

int main() {
    MinStack s;

    s.push(3);
    cout << "Min: " << s.getMin() << "\n";  

    s.push(5);
    cout << "Min: " << s.getMin() << "\n"; 

    s.push(2);
    cout << "Min: " << s.getMin() << "\n";  

    s.push(1);
    cout << "Min: " << s.getMin() << "\n";  

    cout << "Top: " << s.top() << "\n";     
    s.pop();

    cout << "Min after pop: " << s.getMin() << "\n"; 
    cout << "Top after pop: " << s.top() << "\n";      
    s.pop();
    cout << "Min after pop: " << s.getMin() << "\n";  
    cout << "Top after pop: " << s.top() << "\n";      

    return 0;
}
