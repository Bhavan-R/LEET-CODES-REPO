class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        a = [0]
        for b in nums:
            a.append(a[-1] + b)
            
        def c(d, e):
            if e - d <= 1:
                return 0
            
            f = (d + e) // 2
            g = c(d, f) + c(f, e)
            
            h = i = f
            for j in range(d, f):
                while h < e and a[h] - a[j] < lower:
                    h += 1
                while i < e and a[i] - a[j] <= upper:
                    i += 1
                g += (i - h)
            
            a[d:e] = sorted(a[d:e])
            return g

        return c(0, len(a))
