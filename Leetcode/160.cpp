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
        int cnt1 = 0, cnt2 = 0;
        ListNode *ptr = headA;
        while (ptr != nullptr) {
            ptr = ptr->next, cnt1++;
        }
        ptr = headB;
        while (ptr != nullptr) {
            ptr = ptr->next, cnt2++;
        }
        ListNode *ptr2 = headB;
        ptr = headA;
        if (cnt1 > cnt2) {
            for (int i = 1; i <= cnt1 - cnt2; i++) ptr = ptr->next;
        } else {
            for (int i = 1; i <= cnt2 - cnt1; i++) ptr2 = ptr2->next;
        }
        while (ptr != ptr2 && ptr != nullptr && ptr2 != nullptr) {
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        return ptr != nullptr ? ptr : nullptr;
    }
};