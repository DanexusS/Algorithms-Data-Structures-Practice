from typing import List


class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        n = len(names)
        result, h_copy = names.copy(), heights.copy()

        for i in range(n):
            min_idx = i
            for j in range(i + 1, n):
                if h_copy[j] >= h_copy[min_idx]:
                    continue
                min_idx = j

            result[i], result[min_idx] = result[min_idx], result[i]
            h_copy[i], h_copy[min_idx] = h_copy[min_idx], h_copy[i]

        return result
