#include <iostream>
using namespace std;
struct CNode {
    int data;
    CNode* next;
};

CNode* headC = NULL;

void insertLastC(int val) {
    CNode* n = new CNode();
    n->data = val;

    if (!headC) {
        n->next = n;
        headC = n;
        return;
    }
    CNode* temp = headC;
    while (temp->next != headC)
        temp = temp->next;
    temp->next = n;
    n->next = headC;
}
int parity(int x) {
    int count = 0;
    while (x > 0) { 
        if (x & 1) count++;
        x >>= 1;
    }
    return count;
}

void removeEvenParityCLL() {
    if (!headC) return;

    CNode *curr = headC, *prev = NULL;

    // Remove even-head nodes
    while (headC && (parity(headC->data) % 2 == 0)) {

        CNode* last = headC;
        while (last->next != headC)
            last = last->next;

        if (last == headC) { // only one node
            delete headC;
            headC = NULL;
            return;
        }

        CNode* del = headC;
        headC = headC->next;
        last->next = headC;
        delete del;
    }

    if (!headC) return;

    prev = headC;
    curr = headC->next;

    while (curr != headC) {
        if (parity(curr->data) % 2 == 0) { // EVEN parity
            prev->next = curr->next;
            CNode* del = curr;
            curr = curr->next;
            delete del;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void displayCLL() {
    if (!headC) {
        cout << "Empty\n";
        return;
    }

    CNode* t = headC;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != headC);
    cout << "\n";
}
