#include <stdlib.h>

int minimumDistance(int* nums, int numsSize) {
    int ans = -1;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] == nums[j] && nums[j] == nums[k]) {
                    int dist = (j - i) + (k - j) + (k - i);
                    if (ans == -1 || dist < ans) {
                        ans = dist;
                    }
                }
            }
        }
    }

    return ans;
}
