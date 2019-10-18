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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return NULL;

        if (l2 != NULL) l1->val += l2->val;

        if (l1->val > 9) {
            if (l1->next == NULL) l1->next = new ListNode(l1->val / 10);
            l1->val %= 10;
        }

        if (l2 != NULL && l1->next == NULL && l2->next != NULL)
            l1->next = new ListNode(0);

        l1->next = addTwoNumbers(l1->next, l2 == NULL ? l2 : l2->next);

        return l1;
    }
};