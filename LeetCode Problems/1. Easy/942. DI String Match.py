class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        n = len(s)
        minI, maxI = 0, n

        result = []
        for i in s:
            if i == "I":
                result.append(minI)
                minI += 1
            else:
                result.append(maxI)
                maxI -= 1

        result.append(minI)
        return result
