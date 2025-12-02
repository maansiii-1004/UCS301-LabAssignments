#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    n->random = NULL;

    if (!head) {
        n->prev = NULL;
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Search a node with specific value
Node* searchNode(int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// FIX all random pointers (one of them is wrong)
void fixRandomPointers() {
    Node* temp = head;

    while (temp) {
        int expected = 2 * temp->data;
        temp->random = searchNode(expected);  // NULL if not found
        temp = temp->next;
    }
}

void display() {
    Node* t = head;
    while (t) {
        cout << t->data;
        if (t->random)
            cout << "(R=" << t->random->data << ")";
        else
            cout << "(R=NULL)";
        cout << "  <->  ";
        t = t->next;
    }
    cout << "\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    head->random = head->next;        // 10 → 20 (correct)
    head->next->random = head;        // 20 → 10 (WRONG)
    head->next->next->random = NULL;  // 30 → NULL (correct)

    cout << "Before fixing:\n";
    display();

    fixRandomPointers();

    cout << "After fixing:\n";
    display();
}
