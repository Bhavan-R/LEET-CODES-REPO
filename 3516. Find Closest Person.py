class Solution(object):
    def findClosest(self, x, y, z):
        a = abs(x - z)
        b = abs(y - z)
        if a < b:
            return 1
        elif b < a:
            return 2
        else:
            return 0
