class Solution(object):
    def maxSubstringLength(self, s, k):
        if k == 0:
            return True
        n = len(s)
        f = {}
        l = {}
        for i, c in enumerate(s):
            if c not in f:
                f[c] = i
            l[c] = i
        iv = []
        for c in f:
            st = f[c]
            en = l[c]
            j = st
            ok = True
            while j <= en:
                if f[s[j]] < st:
                    ok = False
                    break
                if l[s[j]] > en:
                    en = l[s[j]]
                j += 1
            if ok and not (st == 0 and en == n - 1):
                iv.append((st, en))
        iv.sort(key=lambda x: x[1])
        cnt = 0
        cur = -1
        for st, en in iv:
            if st > cur:
                cnt += 1
                cur = en
        return cnt >= k
