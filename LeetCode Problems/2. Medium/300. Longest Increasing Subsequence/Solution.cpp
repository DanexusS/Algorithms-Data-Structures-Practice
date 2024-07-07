#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lengths(n, 1);
        int result = -1;

        for (int i = n - 1; i >= 0; --i) {
            int longest = 0;

            for (int j = i + 1; j < n; ++j)
                if (nums[i] < nums[j]) longest = max(longest, lengths[j]);

            lengths[i] = longest + 1;
            result = max(lengths[i], result);
        }

        return result;
    }
};
