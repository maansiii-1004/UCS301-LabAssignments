#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    int size() {
        if (!last)
            return 0;

        int count = 0;
        Node* temp = last->next;  // head node
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);

        return count;
    }

    void display() {
        if (!last) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(5);
    cll.insertAtEnd(10);
    cll.insertAtEnd(15);
    cll.insertAtEnd(20);

    cout << "Circular Linked List: ";
    cll.display();

    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}
