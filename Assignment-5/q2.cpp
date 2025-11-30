

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Count occurrences of key and delete all
    void countAndDeleteAll(int key) {
        int count = 0;
        Node* temp = head;

        // Count occurrences
        while (temp) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }

        // Delete all occurrences at the head
        while (head && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        // Delete all other occurrences
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }

        cout << "Count: " << count << ", Updated Linked List: ";
        display();
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Input list: 1->2->1->2->1->3->1
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original Linked List: ";
    list.display();

    int key = 1;
    list.countAndDeleteAll(key);

    return 0;
}
