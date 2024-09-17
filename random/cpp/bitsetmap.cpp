#include <algorithm>
#include <bitset>
#include <map>
#include <vector>

#define ULONGBITSIZE sizeof(unsigned long)*8

struct BitSetComparer {
  bool operator() (const std::bitset<ULONGBITSIZE> &b1, const std::bitset<ULONGBITSIZE> &b2) const {
    return b1.to_ulong() < b2.to_ulong();
  }
};

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
  std::map<std::bitset<ULONGBITSIZE>, std::vector<std::string>, BitSetComparer> bitsets;
  std::bitset<ULONGBITSIZE> currentWordBitSet;
  for (std::string str : strs) {
    currentWordBitSet.reset();
    for (char c : str) currentWordBitSet[c] = 1;
    if (bitsets.contains(currentWordBitSet)) bitsets[currentWordBitSet].push_back(str);
    else bitsets.insert(std::pair<std::bitset<ULONGBITSIZE>, std::vector<std::string>>(currentWordBitSet, {str}));
  }
  std::vector<std::vector<std::string>> resultingVector;
  std::transform(bitsets.begin(), bitsets.end(), std::back_inserter(resultingVector),
    [](std::pair<std::bitset<ULONGBITSIZE>, std::vector<std::string>> p) {
      return p.second;
    }
  );
  return resultingVector;
}
