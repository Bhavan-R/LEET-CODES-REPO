class Solution {
    public int alternatingSubarray(int[] a) {
        int n = a.length, m = -1, c = 1, d = 1;
        for (int i = 1; i < n; i++) {
            int v = a[i] - a[i - 1];
            if (v == d) {
                c++;
                d = -d;
                m = Math.max(m, c);
            } else if (v == 1) {
                c = 2;
                d = -1;
                m = Math.max(m, c);
            } else {
                c = 1;
                d = 1;
            }
        }
        return m;
    }
}
