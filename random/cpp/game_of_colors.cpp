/* You are given an input of 12 tiles. For each tile there is a color and a
 * number. We consider a winning tile when there are 4 patterns fulfilled in
 * the game.
 *
 * Of which, each pattern can be defined as the combination of 3 tiles that
 * fulfills the following:
 * 1. (Same tile) There are three tiles of the same color and number
 * 2. (Consecutive) There are three tiles of consecutive numbers
 *
 * Define a function win() that returns if we are given a winning board.
 */

#include<vector>
#include<string>
/*
#include<queue>
bool win(std::vector<std::pair<std::string, int>> v) {
  int consCount, eq_count, patternCount = 0;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min;
  std::priority_queue<int> max;
  for (std::vector<std::pair<std::string, int>>::iterator itr = v.begin();
  itr != v.end(); itr++) {
    consCount = 1;
    eq_count = 1;
    for (std::vector<std::pair<std::string, int>>::iterator itr2 = v.begin();
    itr2 != v.end(); itr2++) {
      if (itr->first == itr2->first) {
        if (min.empty() || min.top() == itr2->second+1) {
          min.push(itr2->second);
          consCount++;
        }
        else if (max.empty()||max.top() == itr2->second-1) {
          max.push(itr2->second);
          consCount++;
        }
        else if (itr->second == itr2->second) eq_count++;
      }
    }
    if (consCount >= 3 || eq_count >= 3) patternCount++;
  }
  printf("patterns: %i\n", patternCount);
  return patternCount >= 4;
}
*/

#include<map>
bool win(std::vector<std::pair<std::string, int>> v) {
  int patternCount = 0;
  std::map<std::string, std::map<int, int>> m;
  std::map<std::string, std::map<int, int>>::iterator p;
  std::map<int, int>::iterator p2;

  for (std::vector<std::pair<std::string, int>>::iterator itr = v.begin();
  itr != v.end(); itr++) {
    if ((p = m.find(itr->first)) != m.end()) {
      if ((p2 = p->second.find(itr->second)) != p->second.end()) p2->second++;
      else p->second.insert(std::pair<int, int>(itr->second, 1));
    }
    else m.insert(std::pair<std::string, std::map<int, int>>(
          itr->first, std::map<int,int>({{itr->second, 1}}))
    );
  }
  for (std::map<std::string, std::map<int, int>>::iterator itr = m.begin();
  itr != m.end(); itr++) {
    printf("\n%s:\n", itr->first.c_str());
    std::map<int, int>::iterator itr2 = itr->second.begin();
    int min = itr2->first, consCount = 1;
    patternCount += itr2->second/3;

    printf("    at %i[%i][%i], patterns = %i\n", itr2->first, itr2->second,
      consCount,  patternCount);
    itr2++;
    for (; itr2 != itr->second.end(); itr2++) {
      patternCount += itr2->second/3;
      if(min == -1 || itr2->first == min+1) {
        consCount++;
        if (consCount == 3) {
          consCount = 1;
          patternCount++;
        }
      } else consCount = 1;
      min = itr2->first;
      printf("    at %i[%i][%i], patterns = %i\n", itr2->first, itr2->second,
        consCount,  patternCount);
    }
  }
  printf("patternCount %i\n", patternCount);
  return patternCount >= 4;
}

int main() {
  std::vector<std::pair<std::string, int>> v;
  char str[30];
  int n, res;
  for(int i = 0; i < 12; i++) {
    scanf("%s %i", str, &n);
    printf("%s %i\n", ((std::string)str).c_str(), n);
    v.push_back(std::pair<std::string, int>((std::string)str, n));
  }
  scanf("%i", &res);
  if (win(v) && res == 1) printf("WIN\n");
  else printf("LOSE\n");
  return 0;
}
