from collections import Counter


class Solution(object):
    def minimumRounds(self, tasks):
        """
        :type tasks: List[int]
        :rtype: int
        """
        freq = Counter(tasks)
        rounds = 0

        for count in freq.values():
            if count == 1:
                return -1
            rounds += (count + 2) // 3

        return rounds
