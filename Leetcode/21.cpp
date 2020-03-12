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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ret = nullptr, *p = l1, *q = l2;
        if (p == nullptr) {
            ret = q;
            if (q != nullptr) q = q->next;
        } else if (q == nullptr) {
            ret = p;
            p = p->next;
        } else {
            if (p->val < q->val) {
                ret = p;
                p = p->next;
            } else {
                ret = q;
                q = q->next;
            }
        }
        ListNode *k = ret;
        while (!(p == nullptr && q == nullptr)) {
            if (p == nullptr) {
                k->next = q;
                q = q->next;
            } else if (q == nullptr) {
                k->next = p;
                p = p->next;
            } else {
                if (p->val < q->val) {
                    k->next = p;
                    p = p->next;
                } else {
                    k->next = q;
                    q = q->next;
                }
            }
            k = k->next;
        }

        return ret;
    }
};