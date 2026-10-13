class Solution(object):
    def findIntersectionValues(self, nums1, nums2):
        s1 = set(nums1)
        s2 = set(nums2)
        return [sum(1 for x in nums1 if x in s2), sum(1 for x in nums2 if x in s1)]
