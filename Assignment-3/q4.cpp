#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i]) != '\0') {
        // If operand, add to postfix expression
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[k++] = s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(')
                s.pop();  
            else {
                cout << "Invalid Expression: Mismatched parentheses" << endl;
                postfix[0] = '\0';  
                return;
            }
        }
        // If operator
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
          
                if (ch == '^' && s.peek() == '^') break; 
                postfix[k++] = s.pop();
            }
            s.push(ch);
        }
        else if (ch == ' ') {
       
        }
        else {
            cout << "Invalid character in expression: " << ch << endl;
            postfix[0] = '\0';  
            return;
        }
        i++;
    }

    
    while (!s.isEmpty()) {
        if (s.peek() == '(') {
            cout << "Invalid Expression: Mismatched parentheses" << endl;
            postfix[0] = '\0';  
            return;
        }
        postfix[k++] = s.pop();
    }
    postfix[k] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter an infix expression: ";
    cin.getline(infix, MAX);

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0')
        cout << "Postfix expression: " << postfix << endl;

    return 0;
}
