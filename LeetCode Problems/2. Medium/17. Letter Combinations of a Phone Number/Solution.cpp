#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void backtrack(
        string& digits,
        unordered_map<char, string> num_to_char,
        int level,
        string combination,
        vector<string>& result
        ) 
    {
        if (level == digits.size()) {
            result.push_back(combination);
            return;
        }

        for (char c : num_to_char[digits[level]]) {
            backtrack(digits, num_to_char, level + 1, combination + c, result);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};

        unordered_map<char, string> num_to_char = {
            { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
            { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
        };
        vector<string> result;

        backtrack(digits, num_to_char, 0, "", result);

        return result;
    }
};
