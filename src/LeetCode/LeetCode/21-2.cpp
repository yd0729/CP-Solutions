class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *header = new ListNode(-1);

        ListNode *cur = header;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // 合并后 l1 和 l2
        // 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        cur->next = l1 ? l1 : l2;

        auto res = header->next;
        delete header;
        return res;
    }
};