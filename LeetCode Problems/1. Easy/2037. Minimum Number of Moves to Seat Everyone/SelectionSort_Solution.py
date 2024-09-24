from typing import List


class Solution:
    def selection_sort(self, array: List[int]) -> None:
        n = len(array)

        for i in range(n):
            min_idx = i
            for j in range(i + 1, n):
                if array[j] >= array[min_idx]:
                    continue
                min_idx = j

            array[i], array[min_idx] = array[min_idx], array[i]

    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        self.selection_sort(seats)
        self.selection_sort(students)

        res = 0
        for i in range(len(seats)):
            res += abs(seats[i] - students[i])
        return res
