import java.util.*;

class Solution {
    private TreeMap<Integer, Integer> left = new TreeMap<>();
    private TreeMap<Integer, Integer> right = new TreeMap<>();
    private int leftCount = 0, rightCount = 0;
    private long leftSum = 0, rightSum = 0;

    private void add(int val) {
        if (left.isEmpty() || val <= left.lastKey()) {
            left.put(val, left.getOrDefault(val, 0) + 1);
            leftCount++;
            leftSum += val;
        } else {
            right.put(val, right.getOrDefault(val, 0) + 1);
            rightCount++;
            rightSum += val;
        }
        rebalance();
    }

    private void remove(int val) {
        if (left.containsKey(val)) {
            removeOne(left, val);
            leftCount--;
            leftSum -= val;
        } else {
            removeOne(right, val);
            rightCount--;
            rightSum -= val;
        }
        rebalance();
    }

    private void rebalance() {
        while (leftCount > rightCount + 1) {
            int val = left.lastKey();
            removeOne(left, val);
            leftCount--;
            leftSum -= val;
            
            right.put(val, right.getOrDefault(val, 0) + 1);
            rightCount++;
            rightSum += val;
        }
        while (rightCount > leftCount) {
            int val = right.firstKey();
            removeOne(right, val);
            rightCount--;
            rightSum -= val;
            
            left.put(val, left.getOrDefault(val, 0) + 1);
            leftCount++;
            leftSum += val;
        }
    }

    private void removeOne(TreeMap<Integer, Integer> map, int key) {
        int cnt = map.get(key);
        if (cnt == 1) map.remove(key);
        else map.put(key, cnt - 1);
    }

    public long minOperations(int[] nums, int x, int k) {
        int n = nums.length;
        long[] cost = new long[n - x + 1];

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);

            if (i >= x - 1) {
                long median = left.lastKey();
                cost[i - x + 1] = (median * leftCount - leftSum) + (rightSum - median * rightCount);
            }
        }

        long[][] dp = new long[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], Long.MAX_VALUE / 2);
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] != Long.MAX_VALUE / 2) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
}
