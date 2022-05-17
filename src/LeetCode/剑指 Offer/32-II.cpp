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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (not q.empty()) {
            int n = q.size();
            res.emplace_back();
            while (n--) {
                auto f = q.front();
                q.pop();

                if (f->left) {
                    q.push(f->left);
                }
                if (f->right) {
                    q.push(f->right);
                }

                res.back().push_back(f->val);
            }
        }
        return res;
    }
};