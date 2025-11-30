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

    // (a) Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // (b) Insert at end
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

    // (c) Insert before or after a specific value
    void insertBeforeAfter(int target, int val, bool after = true) {
        if (!head) return;

        if (after) {
            Node* temp = head;
            while (temp) {
                if (temp->data == target) {
                    Node* newNode = new Node(val);
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            }
        } else {
            if (head->data == target) {
                insertAtBeginning(val);
                return;
            }
            Node* prev = nullptr;
            Node* curr = head;
            while (curr) {
                if (curr->data == target) {
                    Node* newNode = new Node(val);
                    prev->next = newNode;
                    newNode->next = curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete a specific node by value
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // (g) Search for node and return position from head
    int search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        }
        return -1; // not found
    }

    // (h) Display all node values
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Count occurrences of a key and delete all occurrences
    void countAndDeleteAll(int key) {
        int count = 0;
        Node* temp = head;
        // Count occurrences
        while (temp) {
            if (temp->data == key) count++;
            temp = temp->next;
        }

        // Delete all occurrences
        while (head && head->data == key) {
            deleteFromBeginning();
        }

        if (!head) {
            cout << "Count: " << count << ", Updated Linked List is empty\n";
            return;
        }

        Node* curr = head;
        while (curr->next) {
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

    // Find middle of linked list
    int findMiddle() {
        if (!head) return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    // Reverse linked list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert before/after a node\n";
    cout << "4. Delete from beginning\n";
    cout << "5. Delete from end\n";
    cout << "6. Delete a specific node\n";
    cout << "7. Search for a node\n";
    cout << "8. Display list\n";
    cout << "9. Count occurrences of a key and delete all\n";
    cout << "10. Find middle of list\n";
    cout << "11. Reverse linked list\n";
    cout << "0. Exit\n";
}

int main() {
    LinkedList list;
    int choice;

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            }
            case 3: {
                int target, val;
                char pos;
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Insert before (b) or after (a) the node? ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> val;
                if (pos == 'b')
                    list.insertBeforeAfter(target, val, false);
                else
                    list.insertBeforeAfter(target, val, true);
                break;
            }
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6: {
                int val;
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            }
            case 7: {
                int val;
                cout << "Enter value to search: ";
                cin >> val;
                int pos = list.search(val);
                if (pos == -1)
                    cout << "Node not found.\n";
                else
                    cout << "Node found at position: " << pos << endl;
                break;
            }
            case 8:
                list.display();
                break;
            case 9: {
                int key;
                cout << "Enter key to count and delete: ";
                cin >> key;
                list.countAndDeleteAll(key);
                break;
            }
            case 10: {
                int mid = list.findMiddle();
                if (mid == -1)
                    cout << "List is empty.\n";
                else
                    cout << "Middle element is: " << mid << endl;
                break;
            }
            case 11:
                list.reverse();
                cout << "List reversed.";
                break;
            case 0:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 0);

    return 0;
}
