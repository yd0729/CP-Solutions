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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, inorder, 0, preorder.size());
    }

  private:
    TreeNode *build(vector<int> &preorder, int i, vector<int> &inorder, int j,
                    int len) {
        if (len == 0) {
            return nullptr;
        }

        int root_val = preorder[i];

        int pivot = j;
        for (int k = 0; k < len; k += 1) {
            if (inorder[j + k] == root_val) {
                pivot = j + k;
                break;
            }
        }

        int l_len = pivot - j;
        int r_len = len - l_len - 1;

        TreeNode *node = new TreeNode(
            root_val, build(preorder, i + 1, inorder, j, l_len),
            build(preorder, i + l_len + 1, inorder, pivot + 1, r_len));

        return node;
    }
};