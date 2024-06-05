#!/bin/python3
import sys


DEBUG = True

def strongPasswordChecker(password: str) -> int:
    MIN_LEN, MAX_LEN, REPEAT = 6, 20, 3

    needs_lower, needs_upper, needs_digit = 1, 1, 1 
    needs_delete = max(0, len(password)-MAX_LEN)
    needs_add = max(0, MIN_LEN-len(password))
    prev_char, same_char_count = 0, 1
    
    # How many forcefully need to be changed or added
    count_change = 0

    password += '?'

    for char in password:
        if char == prev_char:
            same_char_count += 1
            continue
        else:
            if same_char_count >= REPEAT:
                count_change += same_char_count//REPEAT

                if needs_delete > 0 and same_char_count%REPEAT == 0:
                    needs_delete -= 1
            same_char_count = 1

        if 'A' <= char <= 'Z':
            needs_upper = 0 
        if 'a' <= char <= 'z':
            needs_lower = 0 
        if '0' <= char <= '9':
            needs_digit = 0 

        prev_char = char

    return needs_delete + max(
        max(count_change, needs_add),
        needs_lower + needs_upper + needs_digit)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Invalid number of arguments")
        exit(1)

    print(strongPasswordChecker(sys.argv[1]))
