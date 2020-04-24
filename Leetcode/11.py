class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans, p, q = 0, 0, len(height)-1
        while p < q:
            ans = max(ans, min(height[p], height[q])*(q-p))
            if height[p] > height[q]:
                q -= 1
            else:
                p += 1
        return ans
