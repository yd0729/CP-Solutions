/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool isBalanced(TreeNode *root) {
        int h = 0;
        return is_balance(root, h);
    }

  private:
    bool is_balance(TreeNode *root, int &h) {
        if (not root) {
            return true;
        }

        int lh = 0, rh = 0;
        bool lb = is_balance(root->left, lh);
        bool rb = is_balance(root->right, rh);
        h = max(lh, rh) + 1;

        if (not lb or not rb or abs(lh - rh) >= 2) {
            return false;
        }

        return true;
    }
};