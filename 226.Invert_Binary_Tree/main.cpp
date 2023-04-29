#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root) {
    if (!root) return nullptr;

    invertTree(root->left);
    invertTree(root->right);
    std::swap(root->left, root->right);
    return root;
}


int main() {
    return 0;
}
