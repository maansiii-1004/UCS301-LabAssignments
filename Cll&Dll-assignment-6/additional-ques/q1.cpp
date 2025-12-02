#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert at end in circular list
void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Split function
void splitCircular(Node** head1, Node** head2) {
    if (head == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    // Use slow/fast to find mid
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd nodes, fast->next->next == head
    fast = (fast->next->next == head) ? fast->next : fast;

    // head1 starts at original head
    *head1 = head;

    // head2 starts at node after slow (mid)
    *head2 = slow->next;

    // Make first list circular
    slow->next = *head1;

    // Make second list circular
    fast->next = *head2;
}

void display(Node* h) {
    if (h == NULL) {
        cout << "Empty\n";
        return;
    }

    Node* temp = h;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != h);
    cout << "\n";
}

int main() {
    // Example list
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    Node* head1 = NULL;
    Node* head2 = NULL;

    splitCircular(&head1, &head2);

    cout << "First Circular List: ";
    display(head1);

    cout << "Second Circular List: ";
    display(head2);

    return 0;
}
