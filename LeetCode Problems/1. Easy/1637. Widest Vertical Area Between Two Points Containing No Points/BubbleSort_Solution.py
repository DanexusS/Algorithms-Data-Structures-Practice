from typing import List


class Solution:
    def bubble_sort(self, array: List[List[int]]):
        n = len(array)

        for i in range(n):
            is_swapped = False

            for j in range(n - i - 1):
                a, b = array[j][0], array[j + 1][0]

                if a <= b:
                    j += 1
                    continue

                array[j][0], array[j + 1][0] = b, a
                is_swapped = True
                
            if not is_swapped:
                break

    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        n = len(points)
        # self.bubble_sort(points)
        points.sort(key=lambda x: x[0])

        result = -1
        for i in range(n - 1):
            result = max(result, points[i + 1][0] - points[i][0])
        
        return result
