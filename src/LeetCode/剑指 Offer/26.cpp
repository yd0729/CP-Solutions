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
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (not A or not B) {
            return false;
        }
        queue<TreeNode *> q;
        q.push(A);
        while (not q.empty()) {
            auto f = q.front();
            q.pop();
            if (_isSubStructure(f, B)) {
                return true;
            }
            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
        return false;
    }

  private:
    bool _isSubStructure(TreeNode *A, TreeNode *B) {
        if (not A or not B) {
            return not B;
        }
        if (A->val == B->val) {
            return _isSubStructure(A->left, B->left) and
                   _isSubStructure(A->right, B->right);
        }
        return false;
    }
};