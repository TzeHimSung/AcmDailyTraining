class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums))


class Solution2:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def backtrack(nums, tmp):
            if not nums:
                ans.append(tmp)
                return
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i+1:], tmp+[nums[i]])
        backtrack(nums, [])
        return ans
