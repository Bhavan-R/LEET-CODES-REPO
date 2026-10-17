class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def get_digit_sum(n):
            s = 0
            while n:
                s += n % 10
                n //= 10
            return s

        n = len(nums)
        arr = []
        for i, val in enumerate(nums):
            arr.append((get_digit_sum(val), val, i))

        arr.sort()

        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or arr[i][2] == i:
                continue

            cycle_size = 0
            curr = i
            while not visited[curr]:
                visited[curr] = True
                curr = arr[curr][2]
                cycle_size += 1

            if cycle_size > 0:
                swaps += cycle_size - 1

        return swaps
