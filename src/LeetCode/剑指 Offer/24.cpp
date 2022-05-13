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
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        auto header = new ListNode();
        while (head) {
            auto temp = header->next;
            header->next = head;
            head = head->next;
            header->next->next = temp;
        }
        head = header->next;
        delete header;

        return head;
    }
};