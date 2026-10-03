class Solution(object):
    def getLongestSubsequence(self, words, groups):
        """
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        ans = []
        last_group = -1
        
        for word, group in zip(words, groups):
            if group != last_group:
                ans.append(word)
                last_group = group
                
        return ans
