class Solution(object):
    def maximumLength(self, nums, k):
        dp = [{} for _ in range(k + 1)]
        max_len = [0] * (k + 1)

        for x in nums:
            for j in range(k, -1, -1):
                same_val = dp[j].get(x, 0) + 1
                diff_val = (max_len[j - 1] + 1) if j > 0 else 0

                best = max(same_val, diff_val)
                dp[j][x] = best

                if best > max_len[j]:
                    max_len[j] = best

        return max_len[k]
