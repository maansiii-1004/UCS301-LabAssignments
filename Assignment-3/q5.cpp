#include <iostream>
#include <cstdlib>  
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; 
        }
        return arr[top--];
    }
};

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int evaluatePostfix(char postfix[]) {
    Stack s;
    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        // If operand (digit), push to stack
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');  // Convert char to int
        }
        // If operator, pop two operands, apply operator and push result
        else if (isOperator(ch)) {
            int val2 = s.pop();
            int val1 = s.pop();
            int res;

            switch (ch) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Division by zero error!" << endl;
                        return -1;
                    }
                    res = val1 / val2; 
                    break;
                default:
                    cout << "Invalid operator encountered." << endl;
                    return -1;
            }
            s.push(res);
        }
        else if (ch == ' ') {
            // Ignore spaces
        }
        else {
            cout << "Invalid character in postfix expression: " << ch << endl;
            return -1;
        }

        i++;
    }

    
    int result = s.pop();
    if (!s.isEmpty()) {
        cout << "Invalid postfix expression." << endl;
        return -1;
    }
    return result;
}

int main() {
    char postfix[MAX];

    cout << "Enter a postfix expression (single digit operands only): ";
    cin.getline(postfix, MAX);

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
