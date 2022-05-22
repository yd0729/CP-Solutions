/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr) {
            return head;
        }
        if (head->val == val) {
            return head->next;
        }
        auto pre = head;
        while (pre->next and pre->next->val != val) {
            pre = pre->next;
        }
        if (not pre->next) {
            return head;
        }
        if (pre->next->val == val) {
            auto tmp = pre->next;
            pre->next = tmp->next;
            delete tmp;
        }
        return head;
    }
};