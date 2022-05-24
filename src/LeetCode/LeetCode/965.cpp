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
    bool isUnivalTree(TreeNode *root) {
        int val = root->val;
        queue<TreeNode *> q;
        q.push(root);

        while (not q.empty()) {
            auto x = q.front();
            q.pop();

            if (x->val != val) {
                return false;
            }

            if (x->left) {
                q.push(x->left);
            }

            if (x->right) {
                q.push(x->right);
            }
        }

        return true;
    }
};