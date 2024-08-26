/* 238. Product of Array Except Self
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 * Constraints:
 * 2 <= nums.length <= 105
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 */
#include<vector>

// Better solution
std::vector<int> productExceptSelf(std::vector<int> &nums) {
  std::vector<int> res = std::vector<int>(nums.size(), 1);
  int prod = 1;
  for (int i = 0; i < nums.size(); i++) {
    res[i] *= prod;
    prod *= nums[i];
  }
  prod = 1;
  for (int i = nums.size()-1; i >= 0; i--) {
    res[i] *= prod;
    prod *= nums[i];
  }
  return res;
}


// Prev solution
int recursiveFrontProductExceptSelf(const std::vector<int> &nums,
const int index, std::vector<int> &dp) {
  if (index == nums.size()-1) {
    dp[index] = 1;
    return 1;
  }
  dp[index] = recursiveFrontProductExceptSelf(nums, index+1, dp)*nums[index+1];
  return dp[index];
}

int recursiveBackProductExceptSelf(const std::vector<int> &nums,
const int index, std::vector<int> &dp) {
  if (index == 0) return 1;
  int prev = recursiveBackProductExceptSelf(nums, index-1, dp)*nums[index-1];
  dp[index] *= prev;
  return prev;
}

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  std::vector<int> res = std::vector<int>(nums.size(), 1);
  recursiveFrontProductExceptSelf(nums, 0, res);
  recursiveBackProductExceptSelf(nums, nums.size()-1, res);
  return res;
}
