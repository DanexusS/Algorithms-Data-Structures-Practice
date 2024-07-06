#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return (nums[0] > nums[1]) ? nums[0] : nums[1];

        vector<int> money(n, 0);
        vector<int> moneyF(n, 0);

        money[1] = nums[1];
        moneyF[0] = nums[0];
        moneyF[1] = moneyF[0];

        for (int i = 2; i < n; ++i) {
            moneyF[i] = max(moneyF[i - 1], nums[i] + moneyF[i - 2]);
            money[i] = max(money[i - 1], nums[i] + money[i - 2]);
        }

        moneyF[n - 1] = -1;

        return max(*max_element(moneyF.begin(), moneyF.end()), *max_element(money.begin(), money.end()));
    }
};
