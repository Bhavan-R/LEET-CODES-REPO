class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        operations = 0
        
        def is_sorted(arr):
            for i in range(len(arr) - 1):
                if arr[i] > arr[i + 1]:
                    return False
            return True

        while not is_sorted(nums):
            min_sum = float('inf')
            min_idx = 0
            
            for i in range(len(nums) - 1):
                pair_sum = nums[i] + nums[i + 1]
                if pair_sum < min_sum:
                    min_sum = pair_sum
                    min_idx = i
            
            nums = nums[:min_idx] + [min_sum] + nums[min_idx + 2:]
            operations += 1

        return operations
