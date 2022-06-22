/* Leetcode 8.
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit
 * signed integer (similar to C/C++'s atoi function).
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 1. Read in and ignore any leading whitespace.
 * 2. Check if the next character (if not already at the end of the string) is '-'
 *  or '+'. Read this character in if it is either. This determines if the final
 *  result is negative or positive respectively. Assume the result is positive
 *  if neither is present.
 * 3. Read in next the characters until the next non-digit character or the end of
 *  the input is reached. The rest of the string is ignored.
 * 4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If
 *  no digits were read, then the integer is 0. Change the sign as necessary
 *  (from step 2).
 * 5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
 *  then clamp the integer so that it remains in the range. Specifically,
 *  integers less than -231 should be clamped to -231, and integers greater
 *  than 231 - 1 should be clamped to 231 - 1.
 * 6. Return the integer as the final result.
 *
 * Note:
 * Only the space character ' ' is considered a whitespace character.
 * Do not ignore any characters other than the leading whitespace or the rest
 * of the string after the digits.
 */
class Solution {
public:
    int myAtoi(string s) {
        // Check length and sign
        if (!s.length()) return 0;
        string::iterator itrb = s.begin(), itrf = s.begin();
        bool sign = true;
        int sum = 0;
        int power = 0;
        
        // Jump whitespaces
        while(itrf != s.end() && *itrf == ' ') itrf++;
        
        // Check if sign is specified
        if (*itrf == '-') {
            sign = false;
            itrf++;
        } else if (*itrf == '+') itrf++;
        
        // Set back iterator
        itrb = itrf;
        
        // Find last number
        while (itrf != s.end() && *itrf >= '0' && *itrf <= '9') itrf++;
        itrf--;
        
        // Sum numbers starting from itrf to itrb
        for (; itrf >= itrb; itrf--) {
            // Max power = 10
            if (power == 9) {
                if ( *itrf > '2' || (*itrf == '2' && ((sign && sum >= 147483647) || (!sign && sum >= 147483648)) ) )
                    return (sign)? 2147483647 : -2147483648;
            } else if (power > 9 && *itrf > '0') return (sign)? 2147483647 : -2147483648;
            
            sum += ((*itrf - '0')*pow(10, power));
            power++;
        }
        
        return (sign)? sum : -sum;
    }
};
