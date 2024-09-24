from typing import List


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        n = len(points)
        points.sort(key=lambda x: x[0])

        result = -1
        for i in range(n - 1):
            result = max(result, points[i + 1][0] - points[i][0])
        
        return result
