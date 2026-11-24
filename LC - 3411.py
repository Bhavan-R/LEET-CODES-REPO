class Solution(object):
    def maxLength(self, nums):
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        n = len(nums)
        m = 2

        for i in range(n):
            p = nums[i]
            g = nums[i]
            l = nums[i]

            for j in range(i + 1, n):
                p *= nums[j]
                g = gcd(g, nums[j])
                l = (l * nums[j]) // gcd(l, nums[j])

                if p == l * g:
                    m = max(m, j - i + 1)

                if p > 25200:
                    break

        return m
