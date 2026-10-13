class Solution(object):
    def maxAlternatingSum(self, nums):
        s = sorted(x * x for x in nums)
        n = len(s)
        k = n // 2
        return sum(s[k:]) - sum(s[:k])
