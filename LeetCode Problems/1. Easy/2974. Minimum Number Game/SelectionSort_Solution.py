from typing import List


class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        n = len(nums)
        t = nums.copy()

        for i in range(n):
            min_idx = i
            for j in range(i + 1, n):
                if t[j] >= t[min_idx]:
                    continue
                min_idx = j

            t[i], t[min_idx] = t[min_idx], t[i]

        for i in range(0, n - 1, 2):
            t[i], t[i + 1] = t[i + 1], t[i]

        return t
