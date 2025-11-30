#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (!head) return true;  

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    string input;
    cout << "Enter a string: ";
    cin >> input;

    for (char ch : input)
        dll.insertAtEnd(ch);

    cout << "Doubly Linked List: ";
    dll.display();

    if (dll.isPalindrome())
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is NOT a palindrome.\n";

    return 0;
}
