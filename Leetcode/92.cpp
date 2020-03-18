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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *pre = ret;
        for (int i = 1; i < m; i++) pre = pre->next;
        ListNode *cur = pre->next;
        for (int i = m; i < n; i++) {
            ListNode *nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return ret->next;
    }
};