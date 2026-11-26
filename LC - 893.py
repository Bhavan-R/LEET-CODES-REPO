class Solution(object):
    def numSpecialEquivGroups(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        a = set()
        for b in words:
            c = "".join(sorted(b[0::2]))
            d = "".join(sorted(b[1::2]))
            a.add((c, d))
        return len(a)
