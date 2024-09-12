#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int t = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (t == g.size()) break;
            if (s[i] < g[t]) continue;
            
            ++t;
            ++result;
        }

        return result;
    }
};
