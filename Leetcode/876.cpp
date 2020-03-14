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
    ListNode *middleNode(ListNode *head) {
        if (head == nullptr) return nullptr;
        int cnt = 1;
        ListNode *ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            cnt++;
        }
        cnt /= 2;
        ptr = head;
        while (cnt--) ptr = ptr->next;
        return ptr;
    }
};