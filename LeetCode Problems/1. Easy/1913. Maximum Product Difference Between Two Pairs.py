from typing import List


class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        max1, max2 = -1, -1
        min1, min2 = 10 ** 9, 10 ** 9

        for n in nums:
            if n < max1:
                if n >= max2:
                    max2 = n
            else:
                max2, max1 = max1, n

            if n > min1:
                if n <= min2:
                    min2 = n
            else:
                min2, min1 = min1, n

        return (max1 * max2) - (min1 * min2)
