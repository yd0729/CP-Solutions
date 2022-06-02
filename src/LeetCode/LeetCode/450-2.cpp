class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        TreeNode *cur = root;
        TreeNode *cur_parent = nullptr;
        int flag = -1;

        while (cur and cur->val != key) {
            cur_parent = cur;
            if (cur->val > key) {
                flag = LEFT;
                cur = cur->left;
            } else {
                flag = RIGHT;
                cur = cur->right;
            }
        }

        if (cur and cur->val == key) {
            TreeNode *new_cur = nullptr;

            if (cur->left and cur->right) { // 2 个孩子
                new_cur = cur->left;
                TreeNode *new_cur_parent = nullptr;

                while (new_cur->right) {
                    new_cur_parent = new_cur;
                    new_cur = new_cur->right;
                }

                if (new_cur_parent) {
                    new_cur_parent->right = new_cur->left;
                    new_cur->left = cur->left;
                }
                
                new_cur->right = cur->right;
            } else if (cur->left) { // 1 个孩子
                new_cur = cur->left;
            } else if (cur->right) {
                new_cur = cur->right;
            }

            delete cur;

            if (cur_parent) {
                if (flag == LEFT) {
                    cur_parent->left = new_cur;
                } else {
                    cur_parent->right = new_cur;
                }
            } else {
                root = new_cur;
            }
        }

        return root;
    }

  private:
    static const int LEFT = 0;
    static const int RIGHT = 1;
};