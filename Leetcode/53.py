class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, currSum = -10000000000000000000, 0
        for i in nums:
            if currSum < 0:
                currSum = i
            else:
                currSum += i
            ans = max(ans, currSum)

        return ans
