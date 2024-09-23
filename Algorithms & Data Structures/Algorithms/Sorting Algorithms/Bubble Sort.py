from typing import List


def bubble_sort(array: List[int]):
    n = len(array)
    
    for i in range(n):
        is_swapped = True
        
        for j in range(n - i - 1):
            if array[j] <= array[j + 1]:
                continue
                
            array[j], array[j + 1] = array[j + 1], array[j]
            is_swapped = False
        
        if not is_swapped:
            break
            
    return array
