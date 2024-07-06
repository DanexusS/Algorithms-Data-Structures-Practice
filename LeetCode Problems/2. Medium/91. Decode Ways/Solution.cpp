#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if (s[0] == '0') return 0;
        if (n == 1) return 1;

        vector<int> nWays(n, 0);
        nWays[0] = 1;
        nWays[1] = (s[1] != '0') + (atoi(s.substr(0, 2).c_str()) < 27);

        for (int i = 2; i < n; ++i) {
            bool good_np = atoi(s.substr(i - 1, 2).c_str()) < 27;
            bool is_prev_zero = s[i - 1] == '0';

            if (is_prev_zero && nWays[i - 1] == 0) break;

            if (s[i] == '0') {
                if (is_prev_zero || !good_np) break;

                nWays[i] = nWays[i - 2];
                continue;
            }

            nWays[i] += !is_prev_zero * nWays[i - 1];
            nWays[i] += good_np * nWays[i - 2 - (i >= 3 && is_prev_zero)];
        }

        return nWays[n - 1];
    }
};
