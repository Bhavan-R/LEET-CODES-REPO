class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        a = [abs(b - c) for b, c in zip(nums1, nums2)]
        d = max(a) if a else 0
        e = [0] * (d + 1)
        for f in a:
            e[f] += 1
        g = k1 + k2
        for h in range(d, 0, -1):
            if e[h] == 0:
                continue
            i = min(g, e[h])
            e[h] -= i
            e[h - 1] += i
            g -= i
            if g == 0:
                break
        return sum(j * j * k for j, k in enumerate(e))
