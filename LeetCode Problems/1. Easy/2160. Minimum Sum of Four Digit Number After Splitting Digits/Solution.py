class Solution:
    def minimumSum(self, num: int) -> int:
        t = sorted([int(i) for i in str(num)])
        return (t[0] + t[1]) * 10 + t[2] + t[3]
