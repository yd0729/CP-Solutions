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
    TreeNode *mirrorTree(TreeNode *root) {
        if (not root) {
            return nullptr;
        }

        auto il = mirrorTree(root->right);
        auto ir = mirrorTree(root->left);

        root->left = il;
        root->right = ir;

        return root;
    }
};