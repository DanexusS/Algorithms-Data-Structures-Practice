from typing import List


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        n = len(names)
        result = names.copy()
        temp = heights.copy()

        for i in range(n):
            is_swapped = False
            for j in range(n - i - 1):
                if temp[j] > temp[j + 1]:
                    continue

                temp[j], temp[j + 1] = temp[j + 1], temp[j]
                result[j], result[j + 1] = result[j + 1], result[j]
                is_swapped = True

            if not is_swapped:
                break

        return result
