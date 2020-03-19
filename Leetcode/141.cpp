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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *p1 = head, *p2 = head;
        do {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 != nullptr) p2 = p2->next;
        } while (p1 != nullptr && p2 != nullptr && p1 != p2);
        return p1 != nullptr && p2 != nullptr;
    }
};