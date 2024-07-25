/* 
 * 42. Trapping Rain Water
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
*/
#include<vector>

int trap(std::vector<int> &height) {
  if (height.size() < 3) return 0;
  std::vector<int>::iterator back = height.begin(), front = height.end()-1;
  std::vector<int>::iterator maxHB = back, maxHF = front;
  int eH = std::min(*back, *front), sum = eH*(distance(back, front)-1), aux;
  while(distance(back, front) > 1) {
    if (*maxHB <= *maxHF) {
      back++;
      if (*back > *maxHB) {
        aux = std::min(*back, *maxHF);
        sum += ((aux-eH)*(distance(back, maxHF)-1))-eH;
        eH = aux;
        maxHB = back;
      } else sum -= *back;
    } else {
      front--;
      if (*front > *maxHF) {
        aux = std::min(*maxHB, *front);
        sum += ((aux-eH)*(distance(maxHB, front)-1))-eH;
        eH = aux;
        maxHF = front;
      } else sum -= *front;
    }
  }
  return sum;
}
