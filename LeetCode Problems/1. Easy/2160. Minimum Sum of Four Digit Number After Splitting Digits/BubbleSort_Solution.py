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

    def minimumSum(self, num: int) -> int:
        temp = [int(i) for i in str(num)]
        self.bubble_sort(temp)
        return (temp[0] + temp[1]) * 10 + temp[2] + temp[3]
