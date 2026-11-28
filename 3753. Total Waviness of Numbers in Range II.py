class Solution(object):
    def totalWaviness(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        def upto(n):
            if n < 100:
                return 0
            digits = [int(ch) for ch in str(n)]
            m = len(digits)
            memo = {}

            def dp(pos, tight, started, prev2, prev1):
                if pos == m:
                    return (1 if started else 0), 0
                key = (pos, tight, started, prev2, prev1)
                if key in memo:
                    return memo[key]

                limit = digits[pos] if tight else 9
                cnt_sum = 0
                wav_sum = 0

                for d in range(limit + 1):
                    ntight = 1 if (tight and d == limit) else 0
                    if not started:
                        if d == 0:
                            c, w = dp(pos + 1, ntight, 0, -1, -1)
                        else:
                            c, w = dp(pos + 1, ntight, 1, -1, d)
                        cnt_sum += c
                        wav_sum += w
                    elif prev2 == -1:
                        c, w = dp(pos + 1, ntight, 1, prev1, d)
                        cnt_sum += c
                        wav_sum += w
                    else:
                        is_wave = (
                            (prev1 > prev2 and prev1 > d) or
                            (prev1 < prev2 and prev1 < d)
                        )
                        add = 1 if is_wave else 0
                        c, w = dp(pos + 1, ntight, 1, prev1, d)
                        cnt_sum += c
                        wav_sum += w + add * c

                memo[key] = (cnt_sum, wav_sum)
                return cnt_sum, wav_sum

            return dp(0, 1, 0, -1, -1)[1]

        return upto(num2) - upto(num1 - 1)
