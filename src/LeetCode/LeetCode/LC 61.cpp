class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }

        auto tail = head;
        int len = 1;
        while (tail->next) { // 找到 tail
            tail = tail->next;
            len += 1;
        }
        tail->next = head; // 连成环

        k = len - (k % len) - 1;
        while (k--) { // 找到应该断开的位置
            head = head->next;
        }
        tail = head;
        head = head->next;
        tail->next = nullptr;

        return head;
    }
};