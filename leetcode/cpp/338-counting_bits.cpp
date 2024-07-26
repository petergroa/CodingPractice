/* 338. Counting Bits
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i
 *
 * Example 1:
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 * Example 2:
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 * Constraints:
 * 0 <= n <= 105
 */
#include<vector>
std::vector<int> countBits(int n) {
  if (n == 0) return std::vector<int>{0};
  std::vector<int> ans = std::vector<int>(n+1);
  ans[0] = 0;
  ans[1] = 1;
  for (int i = 2; i <= n; i++) ans[i] = ans[i/2] + i%2;
  return ans;
}
