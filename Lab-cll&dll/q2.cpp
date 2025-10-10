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

   
    void display() {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }

        Node* head = last->next;
        Node* temp = head;

        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

     
        cout << head->data << endl;
    }
};


int main() {
    CircularLinkedList cll;

   
    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    
    cll.display();

    return 0;
}
