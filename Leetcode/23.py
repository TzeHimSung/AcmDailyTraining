# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        ans = ListNode(0)
        p = ans
        queue = []
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(queue, (lists[i].val, i))
                lists[i] = lists[i].next
        while queue:
            val, idx = heapq.heappop(queue)
            p.next = ListNode(val)
            p = p.next
            if lists[idx]:
                heapq.heappush(queue, (lists[idx].val, idx))
                lists[idx] = lists[idx].next
        return ans.next
