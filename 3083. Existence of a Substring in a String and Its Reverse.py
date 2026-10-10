class Solution(object):
    def isSubstringPresent(self, a):
        b = a[::-1]
        return any(a[c:c+2] in b for c in range(len(a) - 1))
