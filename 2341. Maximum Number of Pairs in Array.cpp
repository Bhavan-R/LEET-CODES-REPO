class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a) {
        int b[101] = {0};
        int c = 0, d = 0;
        
        for (int x : a) {
            b[x]++;
        }
        
        for (int i = 0; i <= 100; ++i) {
            c += b[i] / 2;
            d += b[i] % 2;
        }
        
        return {c, d};
    }
};
