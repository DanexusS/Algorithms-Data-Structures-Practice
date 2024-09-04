#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto num : nums) sum += num;

        if (sum % 2 != 0 || n == 1) return false;

        vector<bool> current;
        vector<bool> previous(sum / 2 + 1, false);

        previous[0] = true;
        if (nums[0] <= sum / 2) previous[nums[0]] = true;

        for (int i = 1; i < n; ++i) {
            current = previous;

            for (int j = 0; j < sum / 2; ++j) {
                if (j + nums[i] > sum / 2) break;
                if (!previous[j]) continue;

                current[j + nums[i]] = true;
            }

            previous = current;
        }

        return current[sum / 2];
    }
};
