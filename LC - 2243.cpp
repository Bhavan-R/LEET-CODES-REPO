class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string t = "";
            for (int i = 0; i < s.length(); i += k) {
                int x = 0;
                for (int j = i; j < i + k && j < s.length(); ++j) {
                    x += s[j] - '0';
                }
                t += to_string(x);
            }
            s = t;
        }
        return s;
    }
};
