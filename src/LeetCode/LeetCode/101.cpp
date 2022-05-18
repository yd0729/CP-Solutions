/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    bool isSymmetric(TreeNode *root) { return isSymmetric(root, root); }

  private:
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if (not a or not b) {
            return a == b;
        }
        if (a->val == b->val) {
            return isSymmetric(a->left, b->right) and
                   isSymmetric(a->right, b->left);
        }
        return false;
    }
};