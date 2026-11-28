from collections import defaultdict


class Solution(object):
    def countPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        seen = defaultdict(int)
        pairs = 0

        for w in words:
            base = ord(w[0]) - ord('a')
            sig = tuple((ord(ch) - ord('a') - base) % 26 for ch in w)
            pairs += seen[sig]
            seen[sig] += 1

        return pairs
