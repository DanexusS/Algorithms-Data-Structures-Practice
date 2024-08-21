#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void bfs(
        unordered_map<string, vector<string>>& graph,
        unordered_map<string, bool>& visited, 
        unordered_map<string, int>& dists,
        string start, 
        string end
    )
    {
        queue<string> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            for (auto n : graph[current]) {
                dists[n] = min(dists[n], dists[current] + 1);

                if (visited[n]) 
                    continue;

                q.push(n);
                visited[n] = true;
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = beginWord.size();
        unordered_map<string, vector<string>> graph;
        unordered_map<string, bool> visited;

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) 
            return 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int t = 0;
                for (int k = 0; k < m; ++k)
                    t += (wordList[i][k] == wordList[j][k]);
                
                if (t == m - 1) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        if (graph[beginWord] == vector(0, string())) {
            for (int i = 0; i < n; ++i) {
                int t = 0;
                for (int j = 0; j < m; ++j)
                    t += (beginWord[j] == wordList[i][j]);
                
                if (t == m - 1) {
                    graph[beginWord].push_back(wordList[i]);
                    graph[wordList[i]].push_back(beginWord);
                }
            }
        }

        unordered_map<string, int> dists;
        for (auto w : wordList)
            dists[w] = INT_MAX;
        dists[beginWord] = 1;

        bfs(graph, visited, dists, beginWord, endWord);

        return (dists[endWord] == INT_MAX) ? 0 : dists[endWord];
    }
};
