#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> graph;

        for (int i = 0; i < edges.size(); ++i) {
            int from = edges[i][0], to = edges[i][1];
            double weight = succProb[i];

            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }

        unordered_map<int, double> distances;
        priority_queue<pair<double, int>> pq;

        pq.push({1, start_node});

        while (!pq.empty()) {
            auto [curW, curV] = pq.top();
            pq.pop();

            if (curV == end_node) return curW;
            if (distances.count(curV) > 0) continue;

            distances[curV] = curW;

            for (auto [nV, nW] : graph[curV]) {
                if (distances.count(nV) > 0) continue;
                pq.push({nW * curW, nV});
            }
        }

        return 0;
    }
};
