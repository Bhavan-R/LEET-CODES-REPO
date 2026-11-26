class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        remove = 10
        alice_turn = True

        while n >= remove and remove > 0:
            n -= remove
            remove -= 1
            alice_turn = not alice_turn

        # If alice_turn is False now, Alice just made the last valid move,
        # meaning Bob cannot move and Alice wins.
        return not alice_turn
