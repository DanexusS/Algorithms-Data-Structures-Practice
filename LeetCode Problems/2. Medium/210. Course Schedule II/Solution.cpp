#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dfs(
        vector<vector<int>>& graph,
        vector<vector<int>>& requirement,
        vector<bool>& visited, 
        int current,
        vector<int>& result
    ) 
    {
        visited[current] = true;
        result.push_back(current);

        for (auto n : graph[current]) {
            if (visited[n]) continue;

            bool flag = true;
            for (auto r : requirement[n]) {
                if (!visited[r]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;

            dfs(graph, requirement, visited, n, result);
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector(0, 0));
        vector<vector<int>> requirement(numCourses, vector(0, 0));

        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            requirement[p[0]].push_back(p[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<int> result;

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i]) continue;

            bool flag = true;
            for (auto r : requirement[i]) {
                if (!visited[r]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;

            dfs(graph, requirement, visited, i, result);
        }

        if (result.size() < numCourses) 
            return {};
        return result;
    }
};
