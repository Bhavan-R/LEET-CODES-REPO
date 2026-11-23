class Solution(object):
    def maxSubarraySum(self, nums):
        n = len(nums)
        vals = sorted(set(nums))
        if len(vals) == 1 and vals[0] <= 0:
            return vals[0]
        
        c = {v: i for i, v in enumerate(vals)}
        m = len(vals)
        
        size = 1
        while size < n:
            size *= 2
            
        INF = 10**18
        s_sum = [0] * (2 * size)
        s_pre = [-INF] * (2 * size)
        s_suf = [-INF] * (2 * size)
        s_ans = [-INF] * (2 * size)
        
        def build():
            for i in range(n):
                idx = size + i
                v = nums[i]
                s_sum[idx] = s_pre[idx] = s_suf[idx] = s_ans[idx] = v
            for i in range(n, size):
                idx = size + i
                s_sum[idx] = 0
                s_pre[idx] = s_suf[idx] = s_ans[idx] = -INF
            for idx in range(size - 1, 0, -1):
                l, r = 2 * idx, 2 * idx + 1
                s_sum[idx] = s_sum[l] + s_sum[r]
                s_pre[idx] = max(s_pre[l], s_sum[l] + s_pre[r])
                s_suf[idx] = max(s_suf[r], s_sum[r] + s_suf[l])
                s_ans[idx] = max(s_ans[l], s_ans[r], s_suf[l] + s_pre[r])

        def update(pos, val, is_deleted):
            idx = size + pos
            if is_deleted:
                s_sum[idx] = 0
                s_pre[idx] = s_suf[idx] = s_ans[idx] = -INF
            else:
                s_sum[idx] = s_pre[idx] = s_suf[idx] = s_ans[idx] = val
            idx //= 2
            while idx >= 1:
                l, r = 2 * idx, 2 * idx + 1
                s_sum[idx] = s_sum[l] + s_sum[r]
                s_pre[idx] = max(s_pre[l], s_sum[l] + s_pre[r])
                s_suf[idx] = max(s_suf[r], s_sum[r] + s_suf[l])
                s_ans[idx] = max(s_ans[l], s_ans[r], s_suf[l] + s_pre[r])
                idx //= 2

        pos_map = [[] for _ in range(m)]
        for i, v in enumerate(nums):
            pos_map[c[v]].append(i)
            
        build()
        res = s_ans[1]
        
        for i, v in enumerate(vals):
            if v >= 0 or len(pos_map[i]) == n:
                continue
            for p in pos_map[i]:
                update(p, 0, True)
            res = max(res, s_ans[1])
            for p in pos_map[i]:
                update(p, v, False)
                
        return res
