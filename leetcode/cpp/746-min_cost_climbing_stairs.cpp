/*
 * 746. Min Cost Climbing Stairs
 * You are given an integer array cost where cost[i] is the cost of ith step
 * on a staircase. Once you pay the cost, you can either climb one or two steps
 *
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 *
 * Example 1:
 * Input: cost = [10,15,20]
 * Output: 15
 *
 * Example 2:
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 */
#include<vector>

int minCostClimbingStairs(std::vector<int> &cost) {
  int dp[cost.size()];
  dp[0] = cost[0];
  dp[1] = cost[1];
  for (int i = 2; i < cost.size(); i++)
    dp[i] = cost[i]+std::min(dp[i-1], dp[i-2]);
  return std::min(dp[cost.size()-1], dp[cost.size()-2]);
}
