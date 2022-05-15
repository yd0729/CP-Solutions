class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
private:
    int depth = 0;
    int sum = 0;
    
    void dfs (TreeNode *root, int dep) {
        if (root == nullptr) {
            return;
        }
        
        dfs(root->left, dep + 1);
        dfs(root->right, dep + 1);
        
        if (dep > depth) {
            depth = dep;
            sum = root->val;
        } else if (dep == depth) {
            sum += root->val;
        }
    }
};