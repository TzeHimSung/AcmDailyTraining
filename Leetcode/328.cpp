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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *p = head, *q = head->next;
        while (p->next != nullptr && q->next != nullptr) {
            p->next = q->next;
            p = p->next;
            q->next = p->next;
            q = q->next;
        }
        p->next = head->next;
        return head;
    }
};