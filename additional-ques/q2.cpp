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

Node* insertEnd(Node* head, int val) {
    Node* n = newNode(val);

    if (!head) return n;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
    return head;
}

// Reverse exactly K nodes, but ONLY IF K nodes exist
Node* reverseK(Node* head, int K) {
    if (!head || K <= 1) return head;

    // Check if at least K nodes exist
    Node* temp = head;
    int count = 0;

    while (temp && count < K) {
        temp = temp->next;
        count++;
    }

    // If nodes < K → DO NOT reverse
    if (count < K)
        return head;

    // Reverse K nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    count = 0;

    while (curr && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

 
    head->next = reverseK(curr, K);

    return prev;   // new head of this block
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    Node* head = NULL;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Original List: ";
    display(head);

    head = reverseK(head, k);

    cout << "After reversing in groups of k: ";
    display(head);

    return 0;
}
