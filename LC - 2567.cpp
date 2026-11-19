class Solution {
public:
    int minimizeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int x = a[n - 1] - a[2];
        int y = a[n - 3] - a[0];
        int z = a[n - 2] - a[1];
        return min({x, y, z});
    }
};
