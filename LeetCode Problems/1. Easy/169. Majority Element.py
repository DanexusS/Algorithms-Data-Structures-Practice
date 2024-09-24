from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        t = {}
        for n in nums:
            t[n] = t.get(n, 0) + 1

        return max(t.items(), key=lambda x: x[1])[0]
