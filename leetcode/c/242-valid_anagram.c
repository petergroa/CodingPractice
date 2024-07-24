/*
 * 242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
 */

#include<stdlib.h>

int isAnagram(char *s, char *t) {
  int *brrayS = (int*)calloc(('z'-'a'+1), sizeof(int));
  int *brrayT = (int*)calloc(('z'-'a'+1), sizeof(int));

  int i;
  for (i = 0 ; s[i] != '\0' && t[i] != '\0'; i++) {
    brrayS[s[i]-'a']++;
    brrayT[t[i]-'a']++;
  }

  for(int i = 0; i < 'z'-'a'; i++)
    if (brrayS[i]^brrayT[i]) {
      free(brrayS);
      free(brrayT);
      return 0;
    }

  free(brrayS);
  free(brrayT);
  return 1;
}
