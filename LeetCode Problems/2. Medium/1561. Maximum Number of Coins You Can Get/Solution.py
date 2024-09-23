from typing import List


class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        n = len(piles)
        temp = sorted(piles.copy(), reverse=True)

        res = 0
        j = n - 1
        for i in range(1, n, 2):
            if i >= j:
                break

            res += temp[i]
            j -= 1

        return res
