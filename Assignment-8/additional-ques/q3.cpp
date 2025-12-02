#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Build tree from level-order input using manual queue (array)
TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode* nodes[1000];   // manual queue
    int front = 0, rear = 0;

    TreeNode* root = new TreeNode(arr[0]);
    nodes[rear++] = root;

    int i = 1;

    while (i < n) {
        TreeNode* curr = nodes[front++];
        
        // Left child
        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            nodes[rear++] = curr->left;
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            nodes[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    int arr[1000];
    int n = 0;

    cout << "Enter tree level-order values (-1 for NULL). End input with any non-number:\n";


    while (cin >> arr[n]) n++;

    TreeNode* root = buildTree(arr, n);

    cout << "Maximum Depth = " << maxDepth(root) << endl;

    return 0;
}
