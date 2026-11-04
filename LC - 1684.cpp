class Solution {
    public int countConsistentStrings(String a, String[] w) {
        boolean[] s = new boolean[26];
        for (int i = 0; i < a.length(); i++) {
            s[a.charAt(i) - 'a'] = true;
        }
        int c = 0;
        for (String x : w) {
            boolean v = true;
            for (int i = 0; i < x.length(); i++) {
                if (!s[x.charAt(i) - 'a']) {
                    v = false;
                    break;
                }
            }
            if (v) c++;
        }
        return c;
    }
}
