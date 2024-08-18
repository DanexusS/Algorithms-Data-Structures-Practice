#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int current) {
        visited[current] = true;

        for (auto n : graph[current]) {
            if (visited[n]) continue;
            dfs(graph, visited, n);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), m = isConnected[0].size();
        vector<vector<int>> graph(n, vector(0, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!isConnected[i][j] || i == j) continue;
                graph[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            ++result;
            dfs(graph, visited, i);
        }

        return result;
    }
};
