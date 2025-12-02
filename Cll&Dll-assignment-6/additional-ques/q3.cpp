#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at end of DLL
void insertEnd(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;

    if (head == NULL) {
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

// Reverse a group of size k
Node* reverseK(Node* start, int k) {
    Node* current = start;
    Node* newHead = NULL;
    int count = 0;

    // Reverse exactly k nodes OR until list ends
    while (current != NULL && count < k) {

        Node* nextNode = current->next;

        // Reverse pointers
        current->next = newHead;
        if (newHead) newHead->prev = current;

        newHead = current;
        current = nextNode;

        count++;
    }

    // 'start' becomes the last node of the reversed group
    start->next = current;
    if (current) current->prev = start;

    return newHead;  // new head of this reversed block
}

// Main function to reverse every group of k
Node* reverseGroups(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* current = head;
    Node* newHead = NULL;
    Node* previousGroupTail = NULL;

    while (current != NULL) {

        Node* groupStart = current;

        // Reverse current group
        Node* groupHead = reverseK(groupStart, k);

        // Connect previous reversed block
        if (newHead == NULL)
            newHead = groupHead;
        else {
            previousGroupTail->next = groupHead;
            groupHead->prev = previousGroupTail;
        }

        previousGroupTail = groupStart;
        current = groupStart->next;
    }

    return newHead;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    insertEnd(70);

    int k = 3;

    cout << "Original DLL: ";
    display(head);

    head = reverseGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    display(head);

    return 0;
}
