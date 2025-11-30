#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// HashSet to store visited node addresses
class HashSet {
    static const int SIZE = 100;
    long long table[SIZE];

public:
    HashSet() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    bool insert(Node* ptr) {
        long long key = (long long)ptr;  // address as key
        int index = key % SIZE;
        if (index < 0) index = -index;

        while (table[index] != -1) {
            if (table[index] == key)
                return false; // already exists → loop detected

            index = (index + 1) % SIZE;
        }

        table[index] = key;
        return true; // inserted
    }
};

// Detect cycle in linked list
bool hasCycle(Node* head) {
    HashSet visited;

    Node* temp = head;
    while (temp != NULL) {
        if (!visited.insert(temp))
            return true; // cycle found

        temp = temp->next;
    }
    return false; // no cycle
}

int main() {
    // Create nodes
    Node *n1 = new Node{1, NULL};
    Node *n2 = new Node{2, NULL};
    Node *n3 = new Node{3, NULL};
    Node *n4 = new Node{4, NULL};

    // Linked list: 1 → 2 → 3 → 4 → 2
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;   // cycle here

    if (hasCycle(n1))
        cout << "true";
    else
        cout << "false";
}
