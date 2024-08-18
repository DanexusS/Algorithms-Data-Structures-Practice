#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dfs(
        unordered_map<string, unordered_map<string, double>>& graph,
        unordered_map<string, bool>& visited,
        double& result,
        double division,
        string current,
        string end
    )
    {
        visited[current] = true;

        if (current == end) {
            result = division;
            return;
        }

        for (auto p : graph[current]) {
            if (visited[p.first]) continue;
            dfs(graph, visited, result, division * p.second, p.first, end);
        }
    }

public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) 
    {
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < n; ++i) {
            vector<string>& eq = equations[i];

            graph[eq[0]][eq[1]] = values[i];
            graph[eq[1]][eq[0]] = 1 / values[i];
        }

        vector<double> result;
        for (auto q : queries) {
            if (graph.find(q[0]) == graph.end() || graph.find(q[1]) == graph.end()) {
                result.push_back(-1);
                continue;
            }
 
            unordered_map<string, bool> visited;
            double res = -1;

            dfs(graph, visited, res, 1, q[0], q[1]);
            result.push_back(res);
        }

        return result;
    }
};
