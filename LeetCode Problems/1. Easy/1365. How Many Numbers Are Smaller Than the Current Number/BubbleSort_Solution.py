from typing import List


class Solution:
    def bubble_sort(self, array: List[int]):
        n = len(array)

        for i in range(n):
            is_swapped = False
            for j in range(n - i - 1):
                if array[j] <= array[j + 1]:
                    continue

                array[j], array[j + 1] = array[j + 1], array[j]
                is_swapped = True

            if not is_swapped:
                break

    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        temp = nums.copy()
        self.bubble_sort(temp)

        res = []
        for n in nums:
            res.append(temp.index(n))

        return res
