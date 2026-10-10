class Solution(object):
    def sortPeople(self, a, b):
        return [c for d, c in sorted(zip(b, a), reverse=True)]
