#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    
    void insertAtEnd(int value) {
        Node* temp = new Node;
        temp->data = value;
        if (last == nullptr) {
            temp->next = temp;
            last = temp;
        } else {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

   
    void insertAtBeginning(int value) {
        Node* temp = new Node;
        temp->data = value;
        if (last == nullptr) {
            temp->next = temp;
            last = temp;
        } else {
            temp->next = last->next;
            last->next = temp;
        }
        cout << "Inserted " << value << " at the beginning.\n";
    }

  
    void deleteNode(int value) {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = last->next;
        Node* prev = last;

        if (last == last->next && last->data == value) {
            delete last;
            last = nullptr;
            cout << "Deleted node with value " << value << ".\n";
            return;
        }

        do {
            if (current->data == value) {
                prev->next = current->next;
                if (current == last) {
                    last = prev;
                }
                delete current;
                cout << "Deleted node with value " << value << ".\n";
                return;
            }
            prev = current;
            current = current->next;
        } while (current != last->next);

        cout << "Node with value " << value << " not found.\n";
    }

    
    void display() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Delete a Node\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            cll.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            cll.insertAtBeginning(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            cll.deleteNode(value);
            break;
        case 4:
            cll.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
