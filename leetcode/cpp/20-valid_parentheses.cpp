/* 20. Valid Parentheses
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 */
#include <string>
#include <stack>

bool isValid(std::string s) {
  std::stack<char> stk;
  for (char c : s) {
    if (c==')')
      if (stk.empty() || stk.top() != c-1)
        return false;
      else
        stk.pop();
    else if (c==']' || c=='}')
      if (stk.empty() || stk.top() != c-2)
        return false;
      else
        stk.pop();
    else
      stk.push(c);
  }
  return stk.empty();
}
