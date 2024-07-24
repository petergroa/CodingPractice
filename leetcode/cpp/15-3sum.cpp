/*
 * 15. 3Sum
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 *
 * Example 2:
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 * Example 3:
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 */

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> v;
  if (nums.size() < 3) return v;

  sort(nums.begin(), nums.end());

  std::vector<int>::iterator target, back, front, prev = nums.end();
  int sum, vt;

  for(target=nums.begin(); target < nums.end()-2; target++) {
    if (prev != nums.end() && *prev == *target) continue;
    vt = (*target)*-1;
    back = target-1;
    front = nums.end()-1;
    while(back != front) {
      sum = *back+*front;
      if (sum == vt) {
        v.push_back(std::vector<int>{*target, *back, *front});
        prev = back;
        while(back != front && *prev == *back) back++;
        prev = front;
        while(front != back && *prev == *front) front--;
      } else if (sum > vt) {
        prev = front;
        while (front != back && *prev == *front) front--;
      } else {
        prev = back;
        while (back != front && *prev == *back) back++;
      }
    }
    prev = target;
  }
  return v;
}
