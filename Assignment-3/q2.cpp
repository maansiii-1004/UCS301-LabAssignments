#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << ch << endl;
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
};

void reverseString(char str[]) {
    Stack s;
    int i = 0;

    while (str[i] != '\0') {
        s.push(str[i]);
        i++;
    }

    
    i = 0;
    while (!s.isEmpty()) {
        str[i++] = s.pop();
    }
    str[i] = '\0';
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);

    reverseString(str);
    cout << "Reversed string: " << str << endl;

    return 0;
}
