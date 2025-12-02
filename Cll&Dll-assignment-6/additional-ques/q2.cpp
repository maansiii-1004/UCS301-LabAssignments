#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* headD = NULL;

void insertLastD(int val) {
    DNode* n = new DNode();
    n->data = val;
    n->next = NULL;

    if (!headD) {
        n->prev = NULL;
        headD = n;
        return;
    }
    DNode* temp = headD;
    while (temp->next) temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

int parity(int x) {
    int count = 0;
    while (x > 0) { 
        if (x & 1) count++;
        x >>= 1;
    }
    return count;
}

void removeEvenParityDLL() {
    DNode* temp = headD;

    while (temp) {
        if (parity(temp->data) % 2 == 0) {  // EVEN PARITY
            DNode* del = temp;

            if (temp->prev) temp->prev->next = temp->next;
            else headD = temp->next; // delete head

            if (temp->next) temp->next->prev = temp->prev;

            temp = temp->next;
            delete del;
        }
        else {
            temp = temp->next;
        }
    }
}

void displayDLL() {
    DNode* t = headD;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << "\n";
}
