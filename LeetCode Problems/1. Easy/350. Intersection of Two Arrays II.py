from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        count = {}
        for n in nums1:
            count[n] = count.get(n, 0) + 1

        res = []
        for n in nums2:
            if not count.get(n):
                continue
            res.append(n)
            count[n] -= 1

        return res
