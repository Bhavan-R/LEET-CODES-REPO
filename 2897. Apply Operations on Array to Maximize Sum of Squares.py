class Solution:
    def maxSum(self, nums, k):
        a = [0] * 30
        for b in nums:
            for c in range(30):
                if (b >> c) & 1:
                    a[c] += 1
        d = 10**9 + 7
        e = 0
        for f in range(k):
            g = 0
            for h in range(30):
                if a[h] > 0:
                    g |= (1 << h)
                    a[h] -= 1
            e = (e + g * g) % d
        return e
