from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
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

        res = []
        for n in nums:
            res.append(temp.index(n))

        return res
