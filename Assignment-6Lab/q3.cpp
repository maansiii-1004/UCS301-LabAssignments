#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    bool visited; 
};

int getLength(Node* head) {
    if (!head) return 0;
    int length = 1;
    Node* temp = head->next;
    while (temp != head) {
        length++;
        temp = temp->next;
    }
    return length;
}

void printCircularMultiples(Node* head, int k) {
    if (!head) return;
    
    int n = getLength(head);
  
    Node* temp = head;
    do {
        temp->visited = false;
        temp = temp->next;
    } while (temp != head);
    
    int printedCount = 0;
    int pass = 0;
    
    while (printedCount < n) {
        temp = head;
        for (int i = 0; i < n; i++) {
            // Check if node is at an index satisfying (i - pass) mod k == 0 and not printed yet
            if (((i - pass) % k + k) % k == 0 && !temp->visited) {
                cout << temp->data << " -> ";
                temp->visited = true;
                printedCount++;
            }
            temp = temp->next;
        }
        pass++;
    }
    cout << "NULL\n";
}

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->visited = false;
    return newNode;
}

int main() {
    // Creating circular linked list: 12->15->18->17->19->20->22->(back to 12)
    Node* head = createNode(12);
    head->next = createNode(15);
    head->next->next = createNode(18);
    head->next->next->next = createNode(17);
    head->next->next->next->next = createNode(19);
    head->next->next->next->next->next = createNode(20);
    head->next->next->next->next->next->next = createNode(22);
    head->next->next->next->next->next->next->next = head;  // Circular

    int k = 3;
    cout << "Output:\n";
    printCircularMultiples(head, k);

    
    Node* current = head->next;
    Node* temp;
    while (current != head) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete head;

    return 0;
}
