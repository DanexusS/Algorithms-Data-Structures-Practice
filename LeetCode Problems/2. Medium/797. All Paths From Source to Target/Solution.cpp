#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dfs(
        vector<vector<int>>& graph,
        vector<vector<int>>& result,
        vector<int> path,
        int cur, 
        int dst
        ) 
    {
        if (cur == dst) {
            result.push_back(path);
            return;
        }

        for (int n : graph[cur]) {
            path.push_back(n);
            dfs(graph, result, path, n, dst);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;

        dfs(graph, result, {0}, 0, n - 1);

        return result;
    }
};
