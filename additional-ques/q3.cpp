#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;
    return n;
}

// Function to detect and remove loop
void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd's algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)   // loop detected
            break;
    }

    // No loop found
    if (slow != fast)
        return;

    // Step 2: Find start of loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Now slow == fast = starting point of loop
    Node* loopStart = slow;

    // Step 3: Remove loop
    Node* temp = loopStart;
    while (temp->next != loopStart)
        temp = temp->next;

    temp->next = NULL; // break the loop
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a list with loop for testing:
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Creating a loop: node 5 -> node 3
    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    cout << "List after removing loop: ";
    printList(head);

    return 0;
}
