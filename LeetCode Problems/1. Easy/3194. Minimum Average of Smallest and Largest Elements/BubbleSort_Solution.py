from typing import List


class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        n = len(nums)
        temp = nums.copy()

        for i in range(n):
            is_swapped = False
            for j in range(n - i - 1):
                if temp[j] <= temp[j + 1]:
                    continue

                temp[j], temp[j + 1] = temp[j + 1], temp[j]
                is_swapped = True

            if not is_swapped:
                break

        i, j = 0, n - 1
        res = 10 ** 9 + 1
        while i <= j:
            res = min(res, (temp[i] + temp[j]) / 2)
            i += 1
            j -= 1

        return res
