// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    unordered_map<Node *, Node *> copied;

    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (not copied.count(head)) {
            Node *copy = new Node(head->val);
            copied[head] = copy;
            copy->next = copyRandomList(head->next);
            copy->random = copyRandomList(head->random);
        }
        return copied[head];
    }
};
