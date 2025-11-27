#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);
    return root;
}

bool searchRec(TreeNode* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;
    return key < root->val ? searchRec(root->left, key) : searchRec(root->right, key);
}

bool searchIter(TreeNode* root, int key) {
    while (root) {
        if (root->val == key) return true;
        root = key < root->val ? root->left : root->right;
    }
    return false;
}

int maxBST(TreeNode* root) {
    while (root->right) root = root->right;
    return root->val;
}

int minBST(TreeNode* root) {
    while (root->left) root = root->left;
    return root->val;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* succ = nullptr;
    while (root) {
        if (p->val < root->val) { succ = root; root = root->left; }
        else root = root->right;
    }
    return succ;
}

TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* pred = nullptr;
    while (root) {
        if (p->val > root->val) { pred = root; root = root->right; }
        else root = root->left;
    }
    return pred;
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    cout << searchRec(root, 25) << endl;
    cout << searchIter(root, 12) << endl;
    cout << maxBST(root) << endl;
    cout << minBST(root) << endl;
    cout << inorderSuccessor(root, root->left)->val << endl;
    cout << inorderPredecessor(root, root->right)->val << endl;
}
