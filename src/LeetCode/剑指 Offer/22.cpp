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
    ListNode *getKthFromEnd(ListNode *head, int k) {  // k 从 1 开始
        auto p1 = head, p2 = head;
        while (k-- > 1) {  // p1 move k - 1 steps
            if (p1 and p1->next) {
                p1 = p1->next;
            } else {
                return nullptr;
            }
        }  // p2 和 p1 相隔 k - 1 steps
        while (p1->next) {  // p1 move to the end
            p1 = p1->next;
            p2 = p2->next;
        }  // p2 是倒数第 k 个
        return p2;
    }
};