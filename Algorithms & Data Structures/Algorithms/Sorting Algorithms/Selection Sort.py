from typing import List


def selectionSort(array: List[int]):
    n = len(array)

    for i in range(n - 1):
        min_idx = i
        for idx in range(i + 1, n - 1):
            if array[idx] < array[min_idx]:
                min_idx = idx

        array[i], array[min_idx] = array[min_idx], array[i]
    return array