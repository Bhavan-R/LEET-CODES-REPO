class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        tree_sum = [0] * (4 * n)
        tree_sq_sum = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def update(node, start, end, l, r, val):
            if lazy[node] != 0:
                add = lazy[node]
                count = end - start + 1
                tree_sq_sum[node] = (tree_sq_sum[node] + 2 * add * tree_sum[node] + count * add * add) % MOD
                tree_sum[node] = (tree_sum[node] + count * add) % MOD
                if start != end:
                    lazy[2 * node] += add
                    lazy[2 * node + 1] += add
                lazy[node] = 0

            if start > end or start > r or end < l:
                return

            if start >= l and end <= r:
                count = end - start + 1
                tree_sq_sum[node] = (tree_sq_sum[node] + 2 * val * tree_sum[node] + count * val * val) % MOD
                tree_sum[node] = (tree_sum[node] + count * val) % MOD
                if start != end:
                    lazy[2 * node] += val
                    lazy[2 * node + 1] += val
                return

            mid = (start + end) // 2
            update(2 * node, start, mid, l, r, val)
            update(2 * node + 1, mid + 1, end, l, r, val)
            tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD
            tree_sq_sum[node] = (tree_sq_sum[2 * node] + tree_sq_sum[2 * node + 1]) % MOD

        def query():
            if lazy[1] != 0:
                add = lazy[1]
                count = n
                return (tree_sq_sum[1] + 2 * add * tree_sum[1] + count * add * add) % MOD
            return tree_sq_sum[1]

        last_pos = {}
        ans = 0

        for i in range(n):
            val = nums[i]
            prev_idx = last_pos.get(val, -1)
            update(1, 0, n - 1, prev_idx + 1, i, 1)
            ans = (ans + query()) % MOD
            last_pos[val] = i

        return ans
