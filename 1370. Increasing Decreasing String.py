class Solution(object):
    def sortString(self, s):
        count = [0] * 26
        for char in s:
            count[ord(char) - ord('a')] += 1
            
        result = []
        total_chars = len(s)
        
        while len(result) < total_chars:
            for i in range(26):
                if count[i] > 0:
                    result.append(chr(ord('a') + i))
                    count[i] -= 1
                    
            for i in range(25, -1, -1):
                if count[i] > 0:
                    result.append(chr(ord('a') + i))
                    count[i] -= 1
                    
        return "".join(result)
