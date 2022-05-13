// Definition for a Node.
class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        // 把拷贝的节点放在原结点的后面
        for (Node *it = head; it != nullptr; it = it->next->next) {
            Node *copy = new Node(it->val);
            copy->next = it->next;
            it->next = copy;
        }
        // 拷贝 random
        for (Node *it = head; it != nullptr; it = it->next->next) {
            Node *copy = it->next;
            copy->random = (it->random != nullptr) ? it->random->next : nullptr;
        }
        // 把拷贝的链表和原链表拆分出来
        Node *head_copy = head->next;
        for (Node *it = head; it != nullptr; it = it->next) {
            Node *copy = it->next;
            it->next = it->next->next;
            copy->next = (copy->next != nullptr) ? copy->next->next : nullptr;
        }

        return head_copy;
    }
};