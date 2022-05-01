class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto cur = new ListNode(0);
        auto res = cur;

        {
            int val[2], carry = 0, sum;
            ListNode* l[] = {l1, l2};

            while (l[0] || l[1] || carry) {
                for (int i = 0; i < 2; i++) {
                    if (l[i]) {
                        val[i] = l[i]->val;
                        l[i] = l[i]->next;
                    } else {
                        val[i] = 0;
                    }
                }

                sum = accumulate(begin(val), end(val), carry);

                cur->next = new ListNode(sum % 10);
                cur = cur->next;
                
                carry = sum / 10;
            }
        }

        auto tmp = res;
        res = res->next;
        delete tmp;
        return res;
    }
};