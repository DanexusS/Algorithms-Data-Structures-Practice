from typing import List


class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        n = len(score)
        temp = [s.copy() for s in score]

        for i in range(n):
            is_swapped = False
            for j in range(n - i - 1):
                if temp[j][k] > temp[j + 1][k]:
                    continue

                temp[j], temp[j + 1] = temp[j + 1], temp[j]
                is_swapped = True

            if not is_swapped:
                break

        return temp
