from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        result = []
        digits = []
        for log in logs:
            if log.split()[1:][0].isdigit():
                digits.append(log)
                continue

            result.append(log)

        result.sort(key=lambda x: (" ".join(x.split()[1:]), x.split()[0]))
        result.extend(digits)

        return result
