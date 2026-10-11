class Solution(object):
    def sumOfSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        return sum(x * x for i, x in enumerate(nums, 1) if n % i == 0)
