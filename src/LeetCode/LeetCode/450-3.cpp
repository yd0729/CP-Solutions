class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (not root) {
            return nullptr;
        }
        if (root->val == key) {
            TreeNode *pre = nullptr;
            if (root->left and root->left) { // 2 个孩子
                pre = root->left;
                TreeNode *pre_parent = nullptr;

                while (pre->right) {
                    pre_parent = pre;
                    pre = pre->right;
                }

                if (pre_parent) {
                    pre_parent->right = pre->left;
                    pre->left = root->left;
                }

                pre->right = root->right;
            } else if (root->left) { // 1 个孩子
                pre = root->left;
            } else if (root->right) {
                pre = root->right;
            }
            delete root;
            return pre;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};