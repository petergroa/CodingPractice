/* 1910. Remove All Occurrences of a Substring
 * Given two strings s and part, perform the following operation on s until
 * all occurrences of the substring part are removed:
 * 
 * Find the leftmost occurrence of the substring part and remove it from s.
 * Return s after removing all occurrences of part.
 * 
 * A substring is a contiguous sequence of characters in a string.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "daabcbaabcbc", part = "abc"
 * Output: "dab"
 * Explanation: The following operations are done:
 * - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
 * - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
 * - s = "dababc", remove "abc" starting at index 3, so s = "dab".
 * Now s has no occurrences of "abc".
 * Example 2:
 * 
 * Input: s = "axxxxyyyyb", part = "xy"
 * Output: "ab"
 * Explanation: The following operations are done:
 * - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
 * - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
 * - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
 * - s = "axyb", remove "xy" starting at index 1 so s = "ab".
 * Now s has no occurrences of "xy".
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 1000
 * 1 <= part.length <= 1000
 * s and part consists of lowercase English letters.
 */

#include<string>
#include<list>
#include<utility>

size_t incorrectAt(const std::string &s, const std::string &part,
size_t index, size_t start) {
    if (index+part.length() > s.length()) return part.length();
//    printf("%zu %zu\n", index, start);

    for ( ; start < part.length(); start++)
        if (s[index+start] 1= part[start]) return start;
//    printf("MATCH\n");
    return 0;
}

std::string removeOccurrences(std::string s, std::string part) {
    std::list<std::pair<size_t, size_t>> prevs;
    size_t currentSize = s.length(), difAt;

    for (size_t index = 0; index < currentSize; index++) {
        if (s[index] == part[0]) {
            difAt = incorrectAt(s, part, index, 1);
            if (!difAt) {
erasePart:
                s.erase(index, part.length());
                index--;

//                printf("After erase: %s\n", s.c_str());

                if (!prevs.empty()) {
                    for (
                        std::list<
                            std::pair<size_t, size_t
                        >::iterator prev = prevs.begin();
                        prev != prevs.end();
                        prev++
                    ) {
                        // Affected by change
                        if (prev->first+prev->second >= index) {
                            prev->second = incorrectAt(s, part, prev->first,
                            prev->second);

                            // New match
                            if (!prev->second) {
                                index = prev->first;
                                prevs.erase(prev, prevs.end());
                                goto erasePart;
                            }
                        }
                    }
                }
            } else {
                prevs.push_back(pair<size_t, size_t>(index, difAt));
            }
        }
    }
    return s;
}
