#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> result = nums;
        vector<int> maxs = nums;

        maxs[0] = nums[0];
        maxs[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            result[i] += maxs[i - 2];
            maxs[i] = max(maxs[i - 1], result[i]);
        }

        return max(result[n - 1], result[n - 2]);
    }
};
