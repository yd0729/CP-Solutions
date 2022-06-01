class Solution {
  public:
    TreeNode *ans;
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return false;
        }

        bool l_found = dfs(root->left, p, q);
        bool r_found = dfs(root->right, p, q);

        if ((l_found && r_found) ||
            ((root->val == p->val || root->val == q->val) &&
             (l_found || r_found))) {
            ans = root;
        }
        return l_found || r_found ||
               (root->val == p->val ||
                root->val == q->val); // 是否找到 p 、 q 中的 1 个
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};