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
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        res.clear();
        if (not root) {
            return res;
        }

        dfs(root, target);
        return res;
    }

  private:
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(TreeNode *root, int target) {
        tmp.push_back(root->val);
        target -= root->val;
        if (root->left or root->right) {
            if (root->left) {
                dfs(root->left, target);
            }
            if (root->right) {
                dfs(root->right, target);
            }
        } else if (target == 0) {
            res.push_back(tmp);
        }
        tmp.pop_back();
    }
};