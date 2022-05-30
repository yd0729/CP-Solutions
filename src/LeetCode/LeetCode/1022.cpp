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
    int sumRootToLeaf(TreeNode *root) {
        sum = 0;
        dfs(root);
        return sum;
    }

  private:
    int sum;
    int val;

    void dfs(TreeNode *node) {
        if (not node) {
            return;
        }

        val = (val << 1) + node->val;

        if (not node->left and not node->right) {
            sum += val;
        } else {
            dfs(node->left);
            dfs(node->right);
        }

        val = val >> 1;
    }
};