#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> is_pal(n + 1, vector(n, false));

        for (int i = 0; i < n; ++i) {
            is_pal[0][i] = true;
            is_pal[1][i] = true;
        }

        int max_len = 1;
        int start_id = 0;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                if (!is_pal[len - 2][i + 1]) continue;
                is_pal[len][i] = s[i] == s[i + len - 1];
                if (!is_pal[len][i] || len < max_len) continue;

                max_len = len;
                start_id = i;
            }
        }

        return s.substr(start_id, max_len);
    }
};
