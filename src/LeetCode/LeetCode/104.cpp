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
    int maxDepth(TreeNode *root) {
        depth = 0;
        max_depth = 0;

        dfs(root);

        return max_depth;
    }

  private:
    int depth;
    int max_depth;

    void dfs(TreeNode *node) {
        if (not node) {
            return;
        }

        max_depth = max(max_depth, ++depth);

        dfs(node->left);
        dfs(node->right);

        depth -= 1;
    }
};