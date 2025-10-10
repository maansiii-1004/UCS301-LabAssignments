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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
    
        if (!head) return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head;  
    }

    bool isCircular() {
        if (!head) return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }

        return (temp == head);
    }

    void display(int limit=20) { 
       
        if (!head) {
            cout << "List is empty.";
            return;
        }
        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < limit) {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << (temp == nullptr ? "NULL" : "(back to head)");
    }
};

int main() {
    LinkedList ll;

    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);

    cout << "Linked List: ";
    ll.display();

    cout << "Is Circular? " << (ll.isCircular() ? "Yes" : "No");

    cout << "Making list circular";
    ll.makeCircular();

    cout << "Linked List after making circular: ";
    ll.display();

    cout << "Is Circular? " << (ll.isCircular() ? "Yes" : "No");

    return 0;
}

