class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        int minFreq = 1e9;
        int ans = -1;

        for (int i = 0; i < 10; ++i) {
            if (freq[i] > 0 && freq[i] < minFreq) {
                minFreq = freq[i];
                ans = i;
            }
        }

        return ans;
    }
};
