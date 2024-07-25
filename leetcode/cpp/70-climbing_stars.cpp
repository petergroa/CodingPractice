/*
 * 70. Climbing Stairs
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Example 1:
 * Input: n = 2
 * Output: 2
 *
 * Example 2:
 * Input: n = 3
 * Output: 3
 */

int climbStairs(int n) {
  if (n<=2) return n;
  int dp[n];
  dp[1] = 1; dp[2] = 2;
  for (int i = 3; i < n; i++) {
    dp[i] = dp[i-1]+dp[i-2];
  }
  return dp[n-1]+dp[n-2];
}
