class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        q = []
        ans = 0
        for v in nums:
            i = bisect.bisect_left(q, -v)
            ans += i
            q[i:i] = [-v]
        return ans