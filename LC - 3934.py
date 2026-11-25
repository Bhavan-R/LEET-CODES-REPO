from collections import Counter


class Solution(object):
    def smallestUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        BASE1, MOD1 = 1315423911, 1000000007
        BASE2, MOD2 = 1000003, 1000000009

        pow1 = [1] * (n + 1)
        pow2 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow1[i] = (pow1[i - 1] * BASE1) % MOD1
            pow2[i] = (pow2[i - 1] * BASE2) % MOD2

        def has_unique_length(length):
            if length > n:
                return False

            h1 = h2 = 0
            for i in range(length):
                val = nums[i] + 1
                h1 = (h1 * BASE1 + val) % MOD1
                h2 = (h2 * BASE2 + val) % MOD2

            freq = Counter([(h1, h2)])
            p1 = pow1[length - 1]
            p2 = pow2[length - 1]

            for i in range(length, n):
                out_val = nums[i - length] + 1
                in_val = nums[i] + 1

                h1 = (h1 - (out_val * p1) % MOD1 + MOD1) % MOD1
                h1 = (h1 * BASE1 + in_val) % MOD1

                h2 = (h2 - (out_val * p2) % MOD2 + MOD2) % MOD2
                h2 = (h2 * BASE2 + in_val) % MOD2

                freq[(h1, h2)] += 1

            return any(count == 1 for count in freq.values())

        lo, hi = 1, n
        ans = n
        while lo <= hi:
            mid = (lo + hi) // 2
            if has_unique_length(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1

        return ans
