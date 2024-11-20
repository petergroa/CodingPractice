/* 1593. Split a String Into the Max Number of Unique Substrings
 * Given a string s, return the maximum number of unique substrings that the
 * given string can be split into.
 * 
 * You can split string s into any list of non-empty substrings, where the
 * concatenation of the substrings forms the original string. However, you must
 * split the substrings such that all of them are unique.
 * 
 * A substring is a contiguous sequence of characters within a string.
 */

// abcdefgfedcbbaaaa
// a b c d e f g                    O(n)
// f:1, e:1, d:1, c:1, b:2, a:4     -
// a:4, b:2, c:1, d:1, e:1, f:1     O(mlogm) where m = n/2
// aa ab ac bd ef                   O(m)
// 12
