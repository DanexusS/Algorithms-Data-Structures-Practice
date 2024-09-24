class Solution:
    def minimumSum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        temp = [int(i) for i in s]

        for i in range(n):
            min_idx = i
            for j in range(i + 1, n):
                if temp[j] >= temp[min_idx]:
                    continue
                min_idx = j

            temp[i], temp[min_idx] = temp[min_idx], temp[i]

        return (temp[0] + temp[1]) * 10 + temp[2] + temp[3]
