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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *headNext = head->next;
        head->next = headNext->next;
        headNext->next = head;
        ListNode *ptr = head->next, *last = head;
        while (ptr != nullptr && ptr->next != nullptr) {
            ListNode *ptrNext = ptr->next;
            ptr->next = ptrNext->next;
            ptrNext->next = ptr;
            last->next = ptrNext;
            ptr = ptr->next;
            last = ptrNext->next;
        }
        return headNext;
    }
};