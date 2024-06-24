#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void _subset(vector<int>& nums, vector<int> subset, vector<vector<int>>& result, int index) {
        result.push_back(subset);

        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            _subset(nums, subset, result, i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        _subset(nums, {}, result, 0);

        return result;
    }
};