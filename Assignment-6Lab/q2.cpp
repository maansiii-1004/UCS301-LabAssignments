#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printMultiples(Node* head, int k) {
    int index = 0;
    Node* current = head;

    while (current != nullptr) {
        if (index % k == 0) {
            cout << current->data << " -> ";
        }
        current = current->next;
        index++;
    }
    cout << "NULL\n";
}


Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int main() {
  
    Node* head = createNode(12);
    head->next = createNode(15);
    head->next->next = createNode(18);
    head->next->next->next = createNode(17);
    head->next->next->next->next = createNode(19);
    head->next->next->next->next->next = createNode(20);
    head->next->next->next->next->next->next = createNode(22);

    int k = 3;
    cout << "Elements at indices multiples of " << k << ": ";
    printMultiples(head, k);

    // Free memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
