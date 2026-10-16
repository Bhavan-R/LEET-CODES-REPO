class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        seen = set()
        curr = 0
        i = 1
        
        while curr not in seen:
            seen.add(curr)
            curr = (curr + i * k) % n
            i += 1
            
        return [p + 1 for p in range(n) if p not in seen]
