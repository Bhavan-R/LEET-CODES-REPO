class Solution(object):
    def longestSubarray(self, nums):
        n = len(nums)
        if n <= 2:
            return n
        p = [1] * n
        for i in range(1, n):
            if nums[i] >= nums[i - 1]:
                p[i] = p[i - 1] + 1
        s = [1] * n
        for i in range(n - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                s[i] = s[i + 1] + 1
        ans = max(max(p), max(s))
        for i in range(n):
            l = p[i - 1] if i > 0 else 0
            r = s[i + 1] if i + 1 < n else 0
            if i > 0 and i + 1 < n and nums[i - 1] <= nums[i + 1]:
                ans = max(ans, l + r + 1)
            else:
                ans = max(ans, l + 1, r + 1)
        return ans
