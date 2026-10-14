class Solution(object):

    def maxSumOfSquares(self, num, sum):
        if sum > 9 * num:
            return ""

        res = []
        rem_sum = sum

        for i in range(num):
            d = min(9, rem_sum)
            res.append(str(d))
            rem_sum -= d

        if rem_sum > 0:
            return ""

        return "".join(res)
