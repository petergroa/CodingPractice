#!/bin/python3
import sys


DEBUG = True

def strongPasswordChecker(password: str) -> int:
    MIN_LEN, MAX_LEN, REPEAT = 6, 20, 3

    needs_lower, needs_upper, needs_digit = 1, 1, 1 
    needs_delete = max(0, len(password)-MAX_LEN)
    needs_add = max(0, MIN_LEN-len(password))
    prev_char, same_char_count = 0, 1
    deleted = 0
    
    # How many forcefully need to be changed or added
    count_change = 0

    password += '?'

    islands = [] # they are what are left after changing a char to avoid repeat

    for char in password:
        if char == prev_char:
            same_char_count += 1
            continue
        else:
            if same_char_count >= REPEAT:
                if needs_delete > 0 and same_char_count%REPEAT == 0:
                    count_change += same_char_count//3 - 1
                    needs_delete -= 1
                    deleted += 1
                else:
                    islands.append(same_char_count)
            same_char_count = 1

        if 'A' <= char <= 'Z':
            needs_upper = 0 
        if 'a' <= char <= 'z':
            needs_lower = 0 
        if '0' <= char <= '9':
            needs_digit = 0 

        prev_char = char

    # Optimal deletions
    # How many deletes can we do instead of changes
    # Sort islands with biggest residuals to delete from there
    islands = sorted(islands, reverse=True, key=lambda x: x%REPEAT)

#    print("Needs add " + str(needs_add) + " | ", 
#        "Count change " + str(count_change) + " | ",
#        "Deleted " + str(deleted) + " | ",
#        "Needs deleted " + str(needs_delete) + " | ",
#        "Needs lower " + str(needs_lower) + " | ",
#        "Needs upper " + str(needs_upper) + " | ",
#        "Needs digit " + str(needs_digit) + " | ")

    for island in islands:
        if needs_delete > 0:
            reduced = min(island, needs_delete)
            count_change += (island-reduced)//3
            deleted += reduced
            needs_delete -= reduced
        else:
            count_change += island//3

    # How many adds
    total = max(max(count_change, needs_add),
            needs_lower+needs_upper+needs_digit)

#    print("Needs add " + str(needs_add) + " | ", 
#        "Count change " + str(count_change) + " | ",
#        "Deleted " + str(deleted) + " | ",
#        "Needs deleted " + str(needs_delete) + " | ",
#        "Needs lower " + str(needs_lower) + " | ",
#        "Needs upper " + str(needs_upper) + " | ",
#        "Needs digit " + str(needs_digit) + " | ")
    return deleted + needs_delete + \
        max(max(count_change, needs_add), # letters can be added between groups
            needs_lower + needs_upper + needs_digit) # secure other params

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Invalid number of arguments")
        exit(1)

    print(strongPasswordChecker(sys.argv[1]))
