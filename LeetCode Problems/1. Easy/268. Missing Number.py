from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        t = sorted(nums)

        for i in range(n + 1):
            if i >= n:
                return n
            if i != t[i]:
                return i
