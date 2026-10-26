class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        if (nums1.back() < nums2.front() || nums2.back() < nums1.front()) {
            return -1;
        }

        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; 
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return -1;
    }
};
