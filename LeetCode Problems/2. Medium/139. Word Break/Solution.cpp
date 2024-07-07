#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m = wordDict.size();
        unordered_map<string, int> sizes;

        for (int i = 0; i < m; ++i) {
            string word = wordDict[i];
            sizes[word] = word.size();
        }

        vector<bool> letter_availability(n + 1, false);
        letter_availability[0] = true;

        for (int i = 0; i < n; ++i) {
            if (!letter_availability[i]) continue;

            for (int j = 0; j < m; ++j) {
                string word = wordDict[j];
                int size = sizes[word];
                
                if (s.substr(i, size) != word) continue;

                letter_availability[i + size] = true;
            }
        }

        return letter_availability[n];
    }
};
