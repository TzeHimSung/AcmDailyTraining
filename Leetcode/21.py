# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ret = ListNode(0)
        p = ret

        while not (l1 == None and l2 == None):
            if l1 == None:
                p.next = l2
                l2 = l2.next
            elif l2 == None:
                p.next = l1
                l1 = l1.next
            elif l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next

        return ret.next
