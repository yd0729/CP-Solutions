class Solution {
  public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return NULL;

        Node *tail = nullptr;
        Node *head = nullptr;

        function<void(Node *)> helper = [&](Node *node) {
            if (node) {
                helper(node->left);

                if (tail) {
                    tail->right = node;
                    node->left = tail;
                } else {
                    head = node;
                }
                tail = node;

                helper(node->right);
            }
        };

        helper(root);

        tail->right = head;
        head->left = tail;

        return head;
    }
};