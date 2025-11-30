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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            newNode->next = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        insertAtBeginning(val);
        last = last->next;
    }

    void insertAfter(int afterVal, int val) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = last->next;
        do {
            if (curr->data == afterVal) {
                Node* newNode = new Node(val);
                newNode->next = curr->next;
                curr->next = newNode;
                if (curr == last)
                    last = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node " << afterVal << " not found.\n";
    }

    void insertBefore(int beforeVal, int val) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = last->next;
        Node* prev = last;
        do {
            if (curr->data == beforeVal) {
                Node* newNode = new Node(val);
                newNode->next = curr;
                prev->next = newNode;
                if (curr == last->next)
                    last->next = newNode;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node " << beforeVal << " not found.\n";
    }

    void deleteNode(int val) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = last->next;
        Node* prev = last;

        do {
            if (curr->data == val) {
                if (curr == last && curr->next == last) {
                    delete curr;
                    last = nullptr;
                    return;
                }

                prev->next = curr->next;

                if (curr == last)
                    last = prev;
                if (curr == last->next)
                    last->next = curr->next;

                delete curr;
                cout << "Node " << val << " deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node " << val << " not found.\n";
    }

    void search(int val) {
        if (!last) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = last->next;
        int pos = 1;
        do {
            if (curr->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            curr = curr->next;
            pos++;
        } while (curr != last->next);

        cout << "Node " << val << " not found.\n";
    }

    void display() {
        if (!last) {
            cout << "Circular Linked List is empty.\n";
            return;
        }

        Node* curr = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != last->next);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val, ref;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After a Node\n4. Insert Before a Node\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display List\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter node to insert after: ";
                cin >> ref;
                cout << "Enter value: ";
                cin >> val;
                cll.insertAfter(ref, val);
                break;
            case 4:
                cout << "Enter node to insert before: ";
                cin >> ref;
                cout << "Enter value: ";
                cin >> val;
                cll.insertBefore(ref, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                cll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                cll.search(val);
                break;
            case 7:
                cll.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
