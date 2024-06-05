#!/bin/python3
import sys

def kthSmallestPrimeFaction(arr: list[int], k: int) -> list[int]:
    current_k : int = 1
    ptr_mx : int = len(arr) - 1
    ptr_min : int = 0
    while current_k <= k and ptr_mx >= 0 and ptr_min < len(arr):
        print(current_k, arr[ptr_min], arr[ptr_mx])
        if arr[ptr_min+1]/arr[ptr_mx] <= arr[ptr_min]/arr[ptr_mx-1]:
            ptr_min += 1
        else:
            ptr_mx -= 1
        current_k += 1
    return [ptr_min, ptr_mx]

def main():
    # input:
    arr = [int(e) for e in sys.argv[1] if e != ' ']
    k = int(sys.argv[2])

    # output
    print(*kthSmallestPrimeFaction(arr, k))

if __name__ == "__main__":
    main()
