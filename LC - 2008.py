from collections import defaultdict

class Solution(object):
    def maxTaxiEarnings(self, n, rides):
        end_to_rides = defaultdict(list)
        for s, e, t in rides:
            end_to_rides[e].append((s, e - s + t))

        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            dp[i] = dp[i - 1]
            for s, profit in end_to_rides[i]:
                dp[i] = max(dp[i], dp[s] + profit)

        return dp[n]
