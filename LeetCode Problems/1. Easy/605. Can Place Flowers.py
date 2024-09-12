class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if (n == 0):
            return True

        f = len(flowerbed)

        if (f < 2):
            return (flowerbed[0] == 0) == n

        planted = (flowerbed[0] == flowerbed[1] == 0)
        flowerbed[0] = 1

        for i in range(1, len(flowerbed) - 1):
            if (flowerbed[i - 1] == flowerbed[i] == flowerbed[i + 1] == 0):
                planted += 1
                flowerbed[i] = 1

        planted += (flowerbed[-1] == flowerbed[-2] == 0)
        
        return planted >= n