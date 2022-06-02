class Solution {
  public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        TreeNode **to_delete = &root;
        while (*to_delete && (*to_delete)->val != key) {
            to_delete = (*to_delete)->val < key ? &(*to_delete)->right
                                                : &(*to_delete)->left;
        }

        if (not *to_delete) {
            return root;
        }

        TreeNode **place = &(*to_delete)->right;
        while (*place) {
            place = &(*place)->left;
        }

        *place = (*to_delete)->left;
        auto tmp = *to_delete;
        *to_delete = (*to_delete)->right;
        delete tmp;

        return root;
    }
};