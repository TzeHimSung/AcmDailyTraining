class Solution:
    def trap(self, height) -> int:
        ans = 0
        leftMax = 0
        rightMax = 0
        for i in range(len(height)):
            leftMax = max(leftMax, height[i])
            rightMax = max(rightMax, height[-i-1])
            ans += leftMax+rightMax-height[i]
        return ans-len(height)*leftMax
