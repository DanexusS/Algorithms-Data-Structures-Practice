from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        n = len(nums)
        temp = nums.copy()

        for i in range(n):
            min_idx = i
            for j in range(i + 1, n):
                if temp[j] >= temp[min_idx]:
                    continue
                min_idx = j
            temp[i], temp[min_idx] = temp[min_idx], temp[i]

        res = []
        for n in nums:
            res.append(temp.index(n))

        return res

