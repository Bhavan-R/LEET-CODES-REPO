from collections import Counter

class Solution(object):
    def countSpecialIntegers(self, nums):
        freq = Counter(nums)
        first = {}
        last = {}
        
        for i, num in enumerate(nums):
            if num not in first:
                first[num] = i
            last[num] = i
            
        ans = 0
        for num in freq:
            if last[num] - first[num] + 1 == freq[num]:
                ans += 1
                
        return ans
