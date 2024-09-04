#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return cost[0];
        
        vector<int> step_cost(n, 1000000000);

        step_cost[0] = cost[0];
        step_cost[1] = cost[1];

        for (int i = 2; i < n; ++i)
            step_cost[i] = min(step_cost[i - 1], step_cost[i - 2]) + cost[i];

        return min(step_cost[n - 1], step_cost[n - 2]);
    }
};
