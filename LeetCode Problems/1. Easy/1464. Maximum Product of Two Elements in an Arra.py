from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        a, b = nums[0], -1

        for i in range(1, len(nums)):
            if nums[i] < a:
                if nums[i] >= b:
                    b = nums[i]
                continue

            b, a = a, nums[i]

        return (a - 1) * (b - 1)
