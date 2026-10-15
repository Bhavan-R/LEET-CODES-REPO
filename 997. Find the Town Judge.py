class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        # Array to track net trust score for each person (1-indexed)
        trust_scores = [0] * (n + 1)
        
        for a, b in trust:
            trust_scores[a] -= 1  # Person 'a' trusts someone, so they lose a point
            trust_scores[b] += 1  # Person 'b' is trusted, so they gain a point
            
        for i in range(1, n + 1):
            # The judge trusts nobody (-0) and is trusted by everyone else (n - 1)
            if trust_scores[i] == n - 1:
                return i
                
        return -1
