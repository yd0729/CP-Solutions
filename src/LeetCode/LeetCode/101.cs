/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool IsSymmetric(TreeNode root) {
        return IsSymmetric(root, root);
    }

    private bool IsSymmetric(TreeNode a, TreeNode b) {
        if (a == null || b == null) {
            return a == b;
        }
        if (a.val == b.val) {
            return IsSymmetric(a.left, b.right) && IsSymmetric(a.right, b.left);
        }
        return false;
    }
}