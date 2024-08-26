/* 49. Group Anagrams
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 *
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * Constraints:
 * 1 <= strs.length <= 104
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 */
#include<map>
#include<vector>
#include<cstdint>
#include<string>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
  std::map<std::vector<uint8_t>, int> anagramMap;
  std::vector<std::vector<std::string>> resultingVector;
  int currentResultingVectorIndex = 0;
  std::vector<uint8_t> currentWordVector = std::vector<uint8_t>('z'-'a'+1, 0);
  for (std::string str : strs) {
    fill(currentWordVector.begin(), currentWordVector.end(), 0);
    for (char c : str) currentWordVector[c-'a'] += 1;

    if (anagramMap.contains(currentWordVector))
      resultingVector[anagramMap[currentWordVector]].push_back(str);
    else {
      anagramMap.insert(std::pair<std::vector<uint8_t>, int>(
        currentWordVector, currentResultingVectorIndex));
      resultingVector.push_back(std::vector<std::string>({str}));
      currentResultingVectorIndex++;
    }
  }
  return resultingVector;
}
