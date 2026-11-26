class Solution(object):
    def destCity(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: str
        """
        outgoing = set()
        for start, _ in paths:
            outgoing.add(start)
        
        for _, dest in paths:
            if dest not in outgoing:
                return dest
        
        return ""
