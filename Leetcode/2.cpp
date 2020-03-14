/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     int carry = 0;
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//         if (l1 == nullptr && l2 == nullptr) {
//             if (!carry) return nullptr;
//             ListNode *ret = new ListNode(carry);
//             return ret;
//         }
//         if (l1 == nullptr) {
//             l2->val += carry;
//             carry = l2->val / 10;
//             l2->val %= 10;
//             l2->next = addTwoNumbers(nullptr, l2->next);
//             return l2;
//         }
//         if (l2 == nullptr) {
//             l1->val += carry;
//             carry = l1->val / 10;
//             l1->val %= 10;
//             l1->next = addTwoNumbers(l1->next, nullptr);
//             return l1;
//         }
//         l1->val = l1->val + l2->val + carry;
//         carry = l1->val / 10;
//         l1->val %= 10;
//         l1->next = addTwoNumbers(l1->next, l2->next);
//         return l1;
//     }
// };

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
    int carry = 0;
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0);
        ListNode *cursor = root;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry) {
            int val_1 = l1 == nullptr ? 0 : l1->val;
            int val_2 = l2 == nullptr ? 0 : l2->val;
            int sum = val_1 + val_2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *nxt = new ListNode(sum);
            cursor->next = nxt;
            cursor = cursor->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return root->next;
    }
};