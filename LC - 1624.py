class Solution(object):
    def maxLengthBetweenEqualCharacters(self, s):
        """
        :type s: str
        :rtype: int
        """
        first_seen = {}
        max_len = -1

        for i, char in enumerate(s):
            if char in first_seen:
                # Subtract 1 to exclude the two matching boundary characters
                max_len = max(max_len, i - first_seen[char] - 1)
            else:
                first_seen[char] = i

        return max_len
