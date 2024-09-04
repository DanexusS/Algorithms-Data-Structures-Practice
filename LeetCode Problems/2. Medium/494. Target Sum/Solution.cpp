#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (auto num : nums) sum += num;

        if (abs(target) > sum) return 0;
        if (n == 1) return (abs(target) == sum);

        vector<int> current;
        vector<int> previous(2 * sum + 1, 0);

        previous[sum + nums[0]] += 1;
        previous[sum - nums[0]] += 1;

        for (int i = 1; i < n; ++i) {
            current = vector(2 * sum + 1, 0);

            for (int j = 0; j <= 2 * sum; ++j) {
                if (previous[j] == 0) continue;

                current[j + nums[i]] += previous[j];
                current[j - nums[i]] += previous[j];
            }

            previous = current;
        }

        return current[sum + target];
    }
};
