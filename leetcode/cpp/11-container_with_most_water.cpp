/* 11. Container With Most Water
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the ith line are (i, 0) and
 * (i, height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 * Example 2:
 * Input: height = [1,1]
 * Output: 1
 */
#include <vector>

int maxArea(std::vector<int>& height) {
  if (height.size() < 2) return 0;
  std::vector<int>::iterator back = height.begin(), front = height.end()-1;
  std::vector<int>::iterator maxHB = back, maxHF = front;
  int area = std::min(*back, *front)*distance(back, front);
  while(distance(back, front) > 1) {
    if (*maxHB <= *maxHF) {
      back++;
      if (*back > *maxHB) {
        maxHB = back;
        area = std::max(area,
          (int)(std::min(*maxHB, *maxHF)*distance(maxHB, maxHF)));
      }
    } else {
      front--;
      if (*front > *maxHF) {
        maxHF = front;
        area = std::max(area,
          (int)(std::min(*maxHB, *maxHF)*distance(maxHB, maxHF)));
      }
    }
  }
  return area;
}
