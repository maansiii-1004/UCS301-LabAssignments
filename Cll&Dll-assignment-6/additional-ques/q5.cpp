#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
};

Node* createNode(int val) {
    Node* n = new Node();
    n->data = val;
    n->next = n->prev = n->up = n->down = NULL;
    return n;
}

// Convert matrix to 4-pointer doubly linked list
Node* convertTo4DLL(int mat[][100], int rows, int cols) {

    Node* nodes[100][100];  

    // Create all nodes
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            nodes[i][j] = createNode(mat[i][j]);

    //  Connect next and prev pointers (row-wise)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (j + 1 < cols)
                nodes[i][j]->next = nodes[i][j + 1];

            if (j - 1 >= 0)
                nodes[i][j]->prev = nodes[i][j - 1];
        }
    }

    //  Connect up and down pointers (column-wise)
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {

            if (i + 1 < rows)
                nodes[i][j]->down = nodes[i + 1][j];

            if (i - 1 >= 0)
                nodes[i][j]->up = nodes[i - 1][j];
        }
    }

    return nodes[0][0];   // return top-left node (head of grid list)
}

// Print the 2D DLL row by row
void printGrid(Node* head, int rows, int cols) {
    Node* rowStart = head;

    for (int i = 0; i < rows; i++) {
        Node* temp = rowStart;
        for (int j = 0; j < cols; j++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        rowStart = rowStart->down;
        cout << "\n";
    }
}

int main() {
    int rows = 3, cols = 3;

    int mat[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = convertTo4DLL(mat, rows, cols);

    cout << "Grid as 4-pointer doubly linked list:\n";
    printGrid(head, rows, cols);

    return 0;
}
