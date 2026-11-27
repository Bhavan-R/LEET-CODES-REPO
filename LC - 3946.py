class Solution(object):
    def maximumSaleItems(self, items, budget):
        n = len(items)
        max_f = max(f for f, _ in items)
        div_cnt = [0] * n
        for i in range(n):
            fi = items[i][0]
            for j in range(n):
                if i != j and items[j][0] % fi == 0:
                    div_cnt[i] += 1

        dp = [-10**9] * (budget + 1)
        dp[0] = 0

        for i in range(n):
            fi, pi = items[i]
            ndp = dp[:]
            if pi <= budget:
                gain = 1 + div_cnt[i]
                for b in range(budget - pi + 1):
                    if dp[b] + gain > ndp[b + pi]:
                        ndp[b + pi] = dp[b] + gain
            dp = ndp

        for i in range(n):
            fi, pi = items[i]
            if pi <= budget:
                for b in range(pi, budget + 1):
                    if dp[b - pi] + 1 > dp[b]:
                        dp[b] = dp[b - pi] + 1

        return max(dp)
