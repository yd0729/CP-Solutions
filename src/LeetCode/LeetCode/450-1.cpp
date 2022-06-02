class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *new_root = root;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left and root->right) {
                TreeNode *succ = root->right;
                while (succ->left) {
                    succ = succ->left;
                }
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            } else {
                if (root->left) {
                    new_root = root->left;
                } else if (root->right) {
                    new_root = root->right;
                } else {
                    new_root = nullptr;
                }
                delete root;
            }
        }

        return new_root;
    }
};