class Solution(object):
    def maxSum(self, nums):
        d = {}
        res = -1
        for x in nums:
            m = max(str(x))
            if m in d:
                if x + d[m] > res:
                    res = x + d[m]
                if x > d[m]:
                    d[m] = x
            else:
                d[m] = x
        return res
