/*
Longest Substring Without Repeating Characters
==============================================
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <stdio.h>

bool containsDuplicate(int* nums, int numsSize) {
  char *brray = (char *)calloc( (INT_MAX/4)+1, sizeof(char));
  int index;
  for (int i = 0; i < num.size(); i++) {
    if (nums[i] < 0) index = (nums[i]*-2)+1; // handle all negatives as odd numbers
    else index = nums[i]*2; // all positives are even numbers

    if ((brray[index/8] & (1<<index%8)) != 0) {
      free(brray);
      return true;
    }
    brray[index/8] |= 1<<(index%8);
  }
  free(brray);
  return false;
}

int main() {
    return 0;
}
