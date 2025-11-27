#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBSTUtil(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->val) && isBSTUtil(root->right, root->val, maxVal);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(25);

    cout << isBST(root) << endl;
}
