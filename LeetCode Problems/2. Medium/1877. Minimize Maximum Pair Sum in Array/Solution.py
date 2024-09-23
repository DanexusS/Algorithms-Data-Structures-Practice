from typing import List


class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        n = len(nums)
        t = sorted(nums)

        i, j = 0, n - 1
        res = -1
        while i <= j:
            res = max(t[i] + t[j], res)
            i += 1
            j -= 1

        return res
