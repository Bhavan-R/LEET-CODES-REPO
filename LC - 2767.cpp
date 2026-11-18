class Solution {
public:
    bool isPowerOfFive(int n) {
        return n > 0 && (15625 % n == 0);
    }

    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 100);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            
            int val = 0;
            for (int j = i; j < n; j++) {
                val = (val << 1) | (s[j] - '0');
                if (isPowerOfFive(val)) {
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
                }
            }
        }
        
        return dp[n] == 100 ? -1 : dp[n];
    }
};
