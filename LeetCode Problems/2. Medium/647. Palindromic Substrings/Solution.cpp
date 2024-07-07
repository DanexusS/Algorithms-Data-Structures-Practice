#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> is_pal(n + 1, vector(n, false));

        for (int i = 0; i < n; ++i) {
            is_pal[0][i] = true;
            is_pal[1][i] = true;
        }

        int result = n;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                if (!is_pal[len - 2][i + 1]) continue;
                is_pal[len][i] = s[i] == s[i + len - 1];

                if (!is_pal[len][i]) continue;
                ++result;
            }
        }

        return result;
    }
};
