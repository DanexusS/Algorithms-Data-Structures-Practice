#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> all_amounts(amount + 1, -1);
        all_amounts[0] = 0;

        for (int i = 0; i < amount; ++i) {
            if (all_amounts[i] == -1) continue;

            for (int j = 0; j < coins.size(); ++j) {
                long next_id = (long)i + coins[j];

                if (next_id > amount) continue;
                
                int& next_amount = all_amounts[next_id];
                int current_length = all_amounts[i] + 1;

                if (next_amount == -1)
                    next_amount = current_length;
                else
                    next_amount = min(next_amount, current_length);
            }
        }

        return all_amounts[amount];
    }
};
