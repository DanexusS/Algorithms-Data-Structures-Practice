#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> repeaters;

        for (auto c : s) {
            repeaters[c] += 1;
        }

        int result = 0;
        bool has_mid = false;
        for (auto [k, v] : repeaters) {
            if (v % 2 == 0) {
                result += v;
                continue;
            }

            if (has_mid) {
                result += v - 1;
                continue;
            }

            result += v;
            has_mid = true;
        }

        return result;
    }
};
