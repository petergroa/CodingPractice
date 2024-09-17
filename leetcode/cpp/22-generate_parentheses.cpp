/* 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * 
 * Input: n = 1
 * Output: ["()"]
 *  
 * 
 * Constraints:
 * 
 * 1 <= n <= 8
 */

#include<string>
#include<vector>

std::vector<std::string> dpGenParen(int n,
std::vector<std::vector<std::string>> &dp) {
  if (n == 0) return std::vector<std::string>();
  if (dp[n-1].empty()) dp[n-1] = dpGenParen(n-1, dp);
  for (int i = 0; i < dp[n-1].size(); i++) {
    dp[n].push_back("("+dp[n-1][i]+")");
    dp[n].push_back("()"+dp[n-1][i]);
    if (i < dp[n-1].size()-1)
      dp[n].push_back(dp[n-1][i]+"()");
  }
  return dp[n];
}

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::vector<std::string>> dp (n+1, std::vector<std::string>());
  dp[0] = std::vector<std::string>();
  dp[1] = std::vector<std::string>({"()"});
  return dpGenParen(n, dp);
}
