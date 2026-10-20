class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());

        int total_sum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool is_sortable = true;

            for (int i = 0; i < n; i += k) {
                int drops = 0;
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k];
                    if (curr > next) {
                        drops++;
                    }
                }

                if (drops > 1) {
                    is_sortable = false;
                    break;
                }

                vector<int> block(nums.begin() + i, nums.begin() + i + k);
                sort(block.begin(), block.end());
                
                for (int j = 0; j < k; ++j) {
                    if (block[j] != s[i + j]) {
                        is_sortable = false;
                        break;
                    }
                }

                if (!is_sortable) break;
            }

            if (is_sortable) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};
