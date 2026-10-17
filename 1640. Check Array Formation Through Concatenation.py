class Solution:
    def canFormArray(self, arr: list[int], pieces: list[list[int]]) -> bool:
        mapping = {piece[0]: piece for piece in pieces}
        i = 0
        n = len(arr)
        while i < n:
            val = arr[i]
            if val not in mapping:
                return False
            piece = mapping[val]
            for num in piece:
                if arr[i] != num:
                    return False
                i += 1
        return True
