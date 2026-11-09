class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001, 0);
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> result;
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        for (int num = 0; num <= 1000; ++num) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }

        return result;
    }
};
