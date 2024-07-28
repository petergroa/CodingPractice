/* 704. Binary Search
 * Given an array of integers nums which is sorted in ascending order, and an
 * integer target, write a function to search target in nums. If target exists,
 * then return its index. Otherwise, return -1.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 *
 * Example 2:
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 * 
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 < nums[i], target < 104
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
 */
#include<vector>
void bs(std::vector<int> &n, const int &target, int &res, int l, int r) {
  if (res) return;
  if (l > r) {
    res = -1;
    return;
  }
  int mid = l+((r-l)/2);
  if(n[mid] == target) {
    res = mid;
    return;
  }
  if (target > n[mid]) bs(n, target, res, mid+1, r);
  else bs(n, target, res, l, mid-1);
}

int search(std::vector<int> &nums, int target) {
  int res = 0;
  bs(nums, target, res, 0, nums.size()-1);
  return res;
}
