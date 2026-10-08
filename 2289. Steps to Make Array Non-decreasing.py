class Solution(object):
    def totalSteps(self, nums):
        n = len(nums)
        dp = [0] * n
        stack = []
        ans = 0
        for i in range(n - 1, -1, -1):
            while stack and nums[i] > nums[stack[-1]]:
                dp[i] = max(dp[i] + 1, dp[stack.pop()])
                ans = max(ans, dp[i])
            stack.append(i)
        return ans
