class Solution(object):
    def findMaxK(self, nums):
        s = set(nums)
        return max([x for x in nums if x > 0 and -x in s] or [-1])
