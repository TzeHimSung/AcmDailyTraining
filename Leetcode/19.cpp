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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) return nullptr;
        ListNode *fastPtr = head, *slowPtr = head;
        while (n--) fastPtr = fastPtr->next;
        if (fastPtr == nullptr) return head->next;
        while (fastPtr->next != nullptr) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        slowPtr->next = slowPtr->next->next;
        return head;
    }
};