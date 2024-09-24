class Solution:
    def minimumSum(self, num: int) -> int:
        temp = [int(i) for i in str(num)]
        n = len(temp)

        for i in range(n):
            is_swapped = False
            for j in range(n - i - 1):
                if temp[j] <= temp[j + 1]:
                    continue

                temp[j], temp[j + 1] = temp[j + 1], temp[j]
                is_swapped = True

            if not is_swapped:
                break

        return (temp[0] + temp[1]) * 10 + temp[2] + temp[3]
