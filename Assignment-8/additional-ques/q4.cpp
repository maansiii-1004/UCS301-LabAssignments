#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Global right-view result array
int rightViewArr[1000];
int rightViewSize = 0;
int maxLevelSeen = -1;

// DFS: visit right first, then left
void rightViewDFS(TreeNode* root, int level) {
    if (root == NULL) return;

    // If this depth is seen first time → add to result
    if (level > maxLevelSeen) {
        rightViewArr[rightViewSize++] = root->val;
        maxLevelSeen = level;
    }

    rightViewDFS(root->right, level + 1);
    rightViewDFS(root->left, level + 1);
}

// Return right-view, builds array in rightViewArr[]
void rightView(TreeNode* root) {
    rightViewSize = 0;
    maxLevelSeen = -1;
    rightViewDFS(root, 0);
}

// Build binary tree from level-order using no STL
TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode* nodes[1000];
    int front = 0, rear = 0;

    TreeNode* root = new TreeNode(arr[0]);
    nodes[rear++] = root;

    int i = 1;

    while (i < n) {
        TreeNode* curr = nodes[front++];

        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            nodes[rear++] = curr->left;
        }
        i++;
        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            nodes[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int arr[1000];
    int n = 0;

    cout << "Enter level-order input (-1 for NULL), end with non-number:\n";

    while (cin >> arr[n]) n++;

    TreeNode* root = buildTree(arr, n);

    rightView(root);

    cout << "Right View: ";
    for (int i = 0; i < rightViewSize; i++)
        cout << rightViewArr[i] << " ";

    return 0;
}
