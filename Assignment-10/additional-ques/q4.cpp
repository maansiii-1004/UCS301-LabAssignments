#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

bool search(Node* head, int x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}


Node* getUnion(Node* head1, Node* head2) {
    Node* unionList = NULL;

    // Insert all elements of list 1
    Node* temp = head1;
    while (temp != NULL) {
        unionList = insert(unionList, temp->data);
        temp = temp->next;
    }

    // Insert elements of list 2 only if not already present
    temp = head2;
    while (temp != NULL) {
        if (!search(unionList, temp->data))
            unionList = insert(unionList, temp->data);
        temp = temp->next;
    }

    return unionList;
}


Node* getIntersection(Node* head1, Node* head2) {
    Node* intersectionList = NULL;

    Node* temp = head1;
    while (temp != NULL) {
        if (search(head2, temp->data)) {
            intersectionList = insert(intersectionList, temp->data);
        }
        temp = temp->next;
    }

    return intersectionList;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Creating list 1: 10 -> 15 -> 4 -> 20
    head1 = insert(head1, 20);
    head1 = insert(head1, 4);
    head1 = insert(head1, 15);
    head1 = insert(head1, 10);

    // Creating list 2: 8 -> 4 -> 2 -> 10
    head2 = insert(head2, 10);
    head2 = insert(head2, 2);
    head2 = insert(head2, 4);
    head2 = insert(head2, 8);

    Node* unionList = getUnion(head1, head2);
    Node* intersectionList = getIntersection(head1, head2);

    cout << "Union: ";
    printList(unionList);

    cout << "Intersection: ";
    printList(intersectionList);

    return 0;
}
