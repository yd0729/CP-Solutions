class Solution {
  public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *successor = nullptr;
        if (p->right != nullptr) {
            successor = p->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            return successor;
        }
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->val > p->val) {
                successor = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return successor;
    }
};