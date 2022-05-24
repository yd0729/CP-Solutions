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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
        int lenB = len(headB);

        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }

        auto i = headA;
        auto j = headB;

        while (lenA > lenB) {
            i = i->next;
            lenA -= 1;
        }

        while (lenA--) {
            if (i == j) {
                return i;
            }

            i = i->next;
            j = j->next;
        }

        return nullptr;
    }

  private:
    int len(ListNode *x) {
        int res = 0;
        while (x) {
            res += 1;
            x = x->next;
        }
        return res;
    }
};