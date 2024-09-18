class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        a, b, c = -1, -1, -1

        for i in triplets:
            if i[0] > target[0] or i[1] > target[1] or i[2] > target[2]:
                continue
            if i[0] != target[0] and i[1] != target[1] and i[2] != target[2]:
                continue
            
            a = max(a, i[0])
            b = max(b, i[1])
            c = max(c, i[2])
        
        return a == target[0] and b == target[1] and c == target[2]
