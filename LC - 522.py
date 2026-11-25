class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def is_subsequence(s, t):
            i = j = 0
            while i < len(s) and j < len(t):
                if s[i] == t[j]:
                    i += 1
                j += 1
            return i == len(s)

        ans = -1
        for i, s in enumerate(strs):
            if len(s) <= ans:
                continue
            if all(i == j or not is_subsequence(s, t) for j, t in enumerate(strs)):
                ans = len(s)

        return ans
