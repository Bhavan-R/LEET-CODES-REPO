class Solution(object):
    def removeOuterParentheses(self, s):
        res = []
        depth = 0
        for char in s:
            if char == '(':
                if depth > 0:
                    res.append(char)
                depth += 1
            else:
                depth -= 1
                if depth > 0:
                    res.append(char)
        return "".join(res)
