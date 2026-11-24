class Solution(object):
    def minOperations(self, nums, k):
        s = set()
        n = len(nums)

        for i in range(n - 1, -1, -1):
            if nums[i] <= k:
                s.add(nums[i])
                if len(s) == k:
                    return n - i

        return n
