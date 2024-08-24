#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void dijkstra(unordered_map<int, vector<pair<int, int>>>& graph, unordered_map<int, int>& distances, int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [curW, curV] = pq.top();
            pq.pop();

            if (distances.count(curV) > 0) continue;
            distances[curV] = curW;

            for (auto [nV, nW] : graph[curV]) {
                if (distances.count(nV) > 0) continue;
                pq.push({curW + nW, nV});
            }
        }
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto t : times) 
            graph[t[0]].push_back({t[1], t[2]});

        unordered_map<int, int> distances;
        dijkstra(graph, distances, k);

        int result = -1;
        for (int i = 1; i <= n; ++i) {
            if (distances.count(i) == 0) return -1;
            result = max(result, distances[i]);
        }

        return result;
    }
};
