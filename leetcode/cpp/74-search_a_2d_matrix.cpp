/* 704. Binary Search
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * Example 2:
 * 
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
 *  
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 104
 * -104 < nums[i], target < 104
 * All the integers in nums are unique.
 * nums is sorted in ascending order.
 */

#include<vector>
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int l = 0, m, r = matrix.size()-1, rw;
  int mc = matrix[0].size()-1;
  while (l <= r) {
    m = l+((r-l)/2);
    if (target < matrix[m][0]) r = m-1;
    else if (target >= matrix[m][0] && target <= matrix[m][mc]) break;
    else l = m+1;
  }
  rw=m, l=0, r=mc;
  while (l <= r) {
    m = l+((r-l)/2);
    if (matrix[rw][m] == target) return true;
    if (target > matrix[rw][m]) l = m+1;
    else r = m-1;
  }
  return false;
}
