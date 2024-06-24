#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void _subset(
        vector<int>& candidates, 
        vector<int> subset, 
        int sum, 
        int& target, 
        int index,
        vector<vector<int>>& result
    ) {
        if (sum == target) {
            result.push_back(subset);
            return;
        }
        if (sum > target)
            return;
        
        for (int i = index; i < candidates.size(); ++i) {
            int c = candidates[i];

            if (sum + c > target)
                return;
            if (i != index && c == candidates[i - 1])
                continue;

            subset.push_back(c);
            _subset(candidates, subset, sum + c, target, i + 1, result);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());
        _subset(candidates, {}, 0, target, 0, result);

        return result;
    }
};