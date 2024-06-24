#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    bool _isPalindrome(string& str) {
        int i = 0, j = str.size() - 1;

        if (j == 0) return true;

        while (i < j) {
            if (str[i] == str[j]) {
                ++i;
                --j;
                continue;
            }

            return false;
        }

        return true;
    }

    void _partition(string& str, int left, int right, vector<string> part, vector<vector<string>>& result) {
        if (left == right) {
            result.push_back(part);
            return;
        }

        string t;

        for (int i = left; i <= right; ++i) {
            t += str[i];
            left += 1;

            if (!_isPalindrome(t))
                continue;

            part.push_back(t);
            _partition(str, left, right, part, result);
            part.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;

        _partition(s, 0, s.size(), {}, result);

        return result;
    }
};