class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        bool is_rev = false;
        queue<TreeNode *> q;
        q.push(root);
        while (not q.empty()) {
            int n = q.size();
            res.emplace_back();
            for (int i = 0; i < n; ++i) {
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
            if (is_rev) {
                reverse(res.back().begin(), res.back().end());
            }
            is_rev = not is_rev;
        }
        return res;
    }
};