#include <iostream>
using namespace std;

// Structure of a tree node
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = NULL;
    }
};


struct NodeList {
    Node** arr;
    int size;
    int capacity;

    NodeList() {
        size = 0;
        capacity = 10;
        arr = new Node*[capacity];
    }

    void add(Node* root) {
        if (size == capacity) {
            capacity *= 2;
            Node** temp = new Node*[capacity];
            for (int i = 0; i < size; i++) temp[i] = arr[i];
            delete[] arr;
            arr = temp;
        }
        arr[size++] = root;
    }
};

// Clone a tree
Node* clone(Node* root) {
    if (!root) return NULL;
    Node* newRoot = new Node(root->val);
    newRoot->left = clone(root->left);
    newRoot->right = clone(root->right);
    return newRoot;
}

// Generate all BSTs for a range
NodeList generate(int start, int end) {
    NodeList result;

    if (start > end) {
        result.add(NULL);
        return result;
    }

    for (int i = start; i <= end; i++) {

        NodeList leftTrees = generate(start, i - 1);
        NodeList rightTrees = generate(i + 1, end);

        for (int l = 0; l < leftTrees.size; l++) {
            for (int r = 0; r < rightTrees.size; r++) {

                Node* root = new Node(i);

                root->left = clone(leftTrees.arr[l]);
                root->right = clone(rightTrees.arr[r]);

                result.add(root);
            }
        }
    }
    return result;
}

NodeList generateTrees(int n) {
    if (n == 0) return NodeList();
    return generate(1, n);
}

void preorder(Node* root) {
    if (!root) {
        cout << "NULL ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    NodeList trees = generateTrees(n);

    cout << "Total BSTs = " << trees.size << "\n\n";

    for (int i = 0; i < trees.size; i++) {
        cout << "Tree " << i + 1 << ": ";
        preorder(trees.arr[i]);
        cout << "\n";
    }

    return 0;
}
