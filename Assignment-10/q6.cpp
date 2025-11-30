#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};


class HashSet {
    static const int SIZE = 100;
    int table[SIZE];

public:
    HashSet() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    bool insert(int key) {
        int index = abs(key) % SIZE;

        while (table[index] != -1) {
            if (table[index] == key)
                return false;        // duplicate found
            index = (index + 1) % SIZE;
        }

        table[index] = key;          // insert
        return true;
    }
};

// ------------ DFS Traversal to Find Duplicate ------------
bool checkDuplicates(Node* root, HashSet &hs) {
    if (root == NULL)
        return false;

    if (!hs.insert(root->data))
        return true; // duplicate


    return checkDuplicates(root->left, hs) ||
           checkDuplicates(root->right, hs);
}

int main() {
 

    Node *n1 = new Node{5, NULL, NULL};
    Node *n2 = new Node{3, NULL, NULL};
    Node *n3 = new Node{8, NULL, NULL};
    Node *n4 = new Node{2, NULL, NULL};
    Node *n5 = new Node{3, NULL, NULL};  // duplicate value 3
    Node *n6 = new Node{7, NULL, NULL};
    Node *n7 = new Node{9, NULL, NULL};

    n1->left = n2; n1->right = n3;
    n2->left = n4; n2->right = n5;
    n3->left = n6; n3->right = n7;

    HashSet hs;

    if (checkDuplicates(n1, hs))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
}
