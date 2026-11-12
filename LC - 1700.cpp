class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int a = 0, b = 0;
        
        for (int s : students) {
            if (s == 0) a++;
            else b++;
        }
        
        for (int s : sandwiches) {
            if (s == 0) {
                if (a == 0) break;
                a--;
            } else {
                if (b == 0) break;
                b--;
            }
        }
        
        return a + b;
    }
};
