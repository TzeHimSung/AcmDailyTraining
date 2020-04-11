class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        dp = [0]*(K+1)
        cnt = 0
        while (dp[K] < N):
            cnt += 1
            for i in range(K, 0, -1):
                dp[i] += dp[i-1]+1
        return cnt
