/* 884. Uncommon Words from Two Sentences
 * A sentence is a string of single-space separated words where each word.
 * consists only of lowercase letters.
 * 
 * A word is uncommon if it appears exactly once in one of the sentences, and
 * does not appear in the other sentence.
 * 
 * Given two sentences s1 and s2, return a list of all the uncommon words. You
 * may return the answer in any order.
 * 
 * Example 1:
 * Input: s1 = "this apple is sweet", s2 = "this apple is sour"
 * Output: ["sweet","sour"]
 * Explanation:
 * The word "sweet" appears only in s1, while the word "sour" appears only in
 * s2.
 * 
 * Example 2:
 * Input: s1 = "apple apple", s2 = "banana"
 * Output: ["banana"]
 * 
 * Constraints:
 * 1 <= s1.length, s2.length <= 200
 * s1 and s2 consist of lowercase English letters and spaces.
 * s1 and s2 do not have leading or trailing spaces.
 * All the words in s1 and s2 are separated by a single space.
 */

#include<unordered_map>
#include<string>
#include<vector>

std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
    std::vector<std::string> result;
    std::unordered_map<std::string, size_t> wordOccurrance;
    size_t front = 0, back = 0;
    for ( ; front <= s1.length() ; ++front) {
        if (s1[front] == ' ' || front == s1.length()) {
            wordOccurrance[s1.substr(back, front-back)] += 1;
            back = front + 1;
        }
    }

    front = 0, back = 0;
    for ( ; front <= s2.length() ; ++front) {
        if (s2[front] == ' ' || front == s2.length()) {
            wordOccurrance[s2.substr(back, front-back)] += 1;
            back = front + 1;
        }
    }

    for(std::pair<std::string, size_t> occ : wordOccurrance) {
        if (occ.second == 1) result.push_back(occ.first);
    }

    return result;
}
