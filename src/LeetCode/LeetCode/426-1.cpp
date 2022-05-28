class Solution {
  public:
    Node *treeToDoublyList(Node *root) {
        if (not root) {
            return nullptr;
        }

        Node *head, *tail;
        treeToDoublyList(root, head, tail);

        head->left = tail;
        tail->right = head;

        return head;
    }

  private:
    // 以 root 为根的树对应的双向链表的头和尾分别是 head 和 tail ．
    void treeToDoublyList(Node *root, Node *&head, Node *&tail) {
        head = root;
        tail = root;

        if (root->left) {
            Node *l_tail;
            treeToDoublyList(root->left, head, l_tail);
            root->left = l_tail;
            l_tail->right = root;
        }

        if (root->right) {
            Node *r_head;
            treeToDoublyList(root->right, r_head, tail);
            root->right = r_head;
            r_head->left = root;
        }
    }
};