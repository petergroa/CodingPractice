/*
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 */

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> ptrs(nums.size());
  iota(ptrs.begin(), ptrs.end(), 0); // fills with increasing values starting from 0
  sort(ptrs.begin(), ptrs.end(), [&](const int &a, const int &b) {
      return nums[a] < nums[b];
  }); // lambda's & passes by reference outside variables. if using = it passes by copy
  int front=0, back=ptrs.size()-1, sum;
  while (front != back) {
    sum = nums[ptrs[front]]+nums[ptrs[back]];
    if (sum == target) return vector<int>{ptrs[front], ptrs[back]};
    if (sum > target) back--;
    else front++;
  }
  return vector<int>();
}
