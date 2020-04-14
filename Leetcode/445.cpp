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
        stack<ListNode *>st1, st2;
        ListNode *p = l1;
        while (p != nullptr) {
            st1.push(p);
            p = p->next;
        }
        p = l2;
        while (p != nullptr) {
            st2.push(p);
            p = p->next;
        }
        ListNode *lastNode = nullptr;
        int carry = 0;
        while (!(st1.empty() && st2.empty())) {
            if (st1.empty()) {
                st2.top()->next = lastNode;
                st2.top()->val += carry;
                carry = st2.top()->val / 10;
                st2.top()->val %= 10;
                lastNode = st2.top();
                st2.pop();
            } else if (st2.empty()) {
                st1.top()->next = lastNode;
                st1.top()->val += carry;
                carry = st1.top()->val / 10;
                st1.top()->val %= 10;
                lastNode = st1.top();
                st1.pop();
            } else {
                st1.top()->next = lastNode;
                st1.top()->val += st2.top()->val + carry;
                carry = st1.top()->val / 10;
                st1.top()->val %= 10;
                lastNode = st1.top();
                st1.pop();
                st2.pop();
            }
        }
        if (carry) {
            ListNode *p = new ListNode(carry);
            p->next = lastNode;
            lastNode = p;
        }
        return lastNode;
    }
};