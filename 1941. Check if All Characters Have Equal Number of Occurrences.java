class Solution {
    public boolean areOccurrencesEqual(String s) {
        int[] freq = new int[26];
        
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        int targetFreq = freq[s.charAt(0) - 'a'];
        
        for (int count : freq) {
            if (count > 0 && count != targetFreq) {
                return false;
            }
        }
        
        return true;
    }
}
