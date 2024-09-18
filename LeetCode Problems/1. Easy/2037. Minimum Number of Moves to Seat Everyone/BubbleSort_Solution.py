class Solution:
    def bubble_sort(self, array: List[int]) -> None:
        n = len(array)
        
        for i in range(n):
            is_swapped = False

            for j in range(n - i - 1):
                if array[j] <= array[j + 1]:
                    continue
                
                array[j], array[j + 1] = array[j + 1], array[j]
                is_swapped = True
            
            if not is_swapped:
                break
            

    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        self.bubble_sort(seats)
        self.bubble_sort(students)

        res = 0
        for i in range(len(seats)):
            res += abs(seats[i] - students[i])
        
        return res
