/* 7. Reverse Integer
 * Given a signed 32-bit integer x, return x with its digits reversed. If
 * reversing x causes the value to go outside the signed 32-bit integer range
 * [-231, 231 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 *
 * Example 1:
 * Input: x = 123
 * Output: 321
 *
 * Example 2:
 * Input: x = -123
 * Output: -321
 *
 * Example 3:
 * Input: x = 120
 * Output: 21
 *
 * Constraints:
 * -231 <= x <= 231 - 1
 */
#include<climits>
int reverse(int x) {
  int res = 0, digit;
  while (x) {
    digit = x%10;
    if (res > INT_MAX ||
        (res == INT_MAX/10 && digit >= INT_MAX%10)) return 0;
    if (res < INT_MIN ||
        (res == INT_MIN/10 && digit <= INT_MIN%10)) return 0;
    res = (res*10)+digit;
    x /= 10;
  }
  return res;
}
