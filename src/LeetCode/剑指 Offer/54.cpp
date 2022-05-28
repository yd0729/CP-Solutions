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
    int kthLargest(TreeNode *root, int k) {
        this->k = k;
        kthLargest(root);
        return val;
    }

  private:
    int k;
    int val;

    void kthLargest(TreeNode *root) {
        if (root->right) {
            kthLargest(root->right);
        }
        if (--k == 0) {
            val = root->val;
            return;
        }
        if (root->left) {
            kthLargest(root->left);
        }
    }
};