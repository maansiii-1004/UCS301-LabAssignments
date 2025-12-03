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


Node* append(Node* head, int val) {
    Node* n = newNode(val);

    if (!head) return n;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;

    return head;
}

// Find length
int getLength(Node* head) {
    int cnt = 0;
    while (head) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

// MAIN INTERSECTION LOGIC
Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = len1 - len2;

    Node* p1 = head1;
    Node* p2 = head2;

    if (diff > 0) {
        while (diff--) p1 = p1->next;
    } else {
        diff = -diff;
        while (diff--) p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}

int main() {
    Node *head1 = NULL, *head2 = NULL, *common = NULL;
    int n1, n2, nc, val;

    // ------------------ INPUT LIST 1 ------------------
    cout << "Enter number of nodes in List 1: ";
    cin >> n1;

    cout << "Enter elements of List 1:\n";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        head1 = append(head1, val);
    }

    // ------------------ INPUT LIST 2 ------------------
    cout << "Enter number of nodes in List 2: ";
    cin >> n2;

    cout << "Enter elements of List 2:\n";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        head2 = append(head2, val);
    }

    // ------------------ INPUT COMMON LIST ------------------
    cout << "Enter number of nodes in COMMON merged part: ";
    cin >> nc;

    cout << "Enter elements of COMMON part:\n";
    for (int i = 0; i < nc; i++) {
        cin >> val;
        common = append(common, val);
    }

    // Attach common part to both lists (creating Y-shape)
    if (head1) {
        Node* t = head1;
        while (t->next) t = t->next;
        t->next = common;
    }

    if (head2) {
        Node* t = head2;
        while (t->next) t = t->next;
        t->next = common;
    }


    Node* ans = getIntersection(head1, head2);

    if (ans)
        cout << "Intersection at node with value: " << ans->data << "\n";
    else
        cout << "No intersection found.\n";

    return 0;
}
