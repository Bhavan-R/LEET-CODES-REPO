class Solution(object):
    def smallestAbsent(self, nums):
        avg = sum(nums) / len(nums)

        x = int(avg) + 1

        while True:
            if x > 0 and x not in nums:
                return x
            x += 1
