class Solution:
    def maximum69Number (self, num: int) -> int:
        x = 0
        t = str(num)
        for i in range(len(t)):
            if t[i] == "6":
                x = 3 * 10 ** (len(t) - i - 1)
                break
        
        return num + x
        