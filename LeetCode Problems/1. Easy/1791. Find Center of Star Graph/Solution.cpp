#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<bool> visited(edges.size() + 1, false);

        for (auto pair : edges) {
            if (visited[pair[0] - 1]) return pair[0];
            if (visited[pair[1] - 1]) return pair[1];

            visited[pair[0] - 1] = true;
            visited[pair[1] - 1] = true;
        }

        return -1;
    }
};
