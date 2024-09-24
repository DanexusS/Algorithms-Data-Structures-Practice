from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(n):
            nums1[m + i] = nums2[i]

        for i in range(m + n):
            min_idx = i
            for j in range(i + 1, m + n):
                if nums1[j] >= nums1[min_idx]:
                    continue
                min_idx = j
            nums1[i], nums1[min_idx] = nums1[min_idx], nums1[i]
