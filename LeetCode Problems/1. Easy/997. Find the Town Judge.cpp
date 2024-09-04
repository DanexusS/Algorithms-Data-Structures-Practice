#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n, vector(0, 0));

        for (auto tr : trust)
            adj[tr[0] - 1].push_back(tr[1] - 1);

        vector<int> trusts(n, 0);
        vector<int> pos_jud;
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[i].size() == 0) {
                pos_jud.push_back(i);
                continue;
            }
            for (auto n : adj[i])
                ++trusts[n];
        }

        for (auto j : pos_jud)
            if (trusts[j] == n - 1)
                return j + 1;
        return -1;
    }
};
