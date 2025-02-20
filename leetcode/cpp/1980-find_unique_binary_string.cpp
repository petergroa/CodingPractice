/* 1980. Find Unique Binary String
 * Given an array of strings nums containing n unique binary strings each of
 * length n, return a binary string of length n that does not appear in nums.
 * If there are multiple answers, you may return any of them.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = ["01","10"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "00" would also be correct.
 * Example 2:
 * 
 * Input: nums = ["00","01"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "10" would also be correct.
 * Example 3:
 * 
 * Input: nums = ["111","011","001"]
 * Output: "101"
 * Explanation: "101" does not appear in nums. "000", "010", "100", and "110"
 * would also be correct.
 *  
 * 
 * Constraints:
 * 
 * n == nums.length
 * 1 <= n <= 16
 * nums[i].length == n
 * nums[i] is either '0' or '1'.
 * All the strings of nums are unique.
 */
#include<bitset>
#include<cstdint>
#include<iterator>
#include<string>
#include<vector>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"

#define BYTE_TO_BINARY(byte) \
    ((byte) & 0x80 ? '1':'0'), \
    ((byte) & 0x40 ? '1':'0'), \
    ((byte) & 0x20 ? '1':'0'), \
    ((byte) & 0x10 ? '1':'0'), \
    ((byte) & 0x08 ? '1':'0'), \
    ((byte) & 0x04 ? '1':'0'), \
    ((byte) & 0x02 ? '1':'0'), \
    ((byte) & 0x01 ? '1':'0')

uint16_t stringToNum(const std::string &str) {
    uint16_t num = 0;
    uint8_t i = 0;

    for (std::string::const_reverse_iterator ritr = str.rbegin();
    ritr != str.end(); ++i, ++ritr) {
        if (*ritr == '1') num |= (1 << i);
    }

    return num;
}

std::string numToString(uint16_t &num, int len) {
//    printf("\tnumToString => len: %i, num: %i = ", len, num);
    std::string out = std::string(len, '0');
    for (uint8_t bit = 0; len > 0; ++bit, --len) {
        if (num&(1 << bit)) {
            out[len-1]++;
            num ^= (1 << bit);
        }

        if (num == 0) break;
    }
//    printf("%s\n", out.c_str());
    return out;
}

std::string findDifferentBinaryString(const std::vector<std::string> &nums) {
    std::bitset<65536> visited;
    uint16_t pointingTo = 0, current;

    for (std::string num : nums) {
//        printf("num: %s", num.c_str());

        current = stringToNum(num);
//        printf(", transformed: %i", current);

        if (pointingTo == current) {
            do { ++pointingTo; } while (visited[pointingTo]);
//            printf(", new visited: %i" BYTE_TO_BINARY_PATTERN ")", pointingTo,
//                   BYTE_TO_BINARY(pointingTo));
        }
//        printf("\n");
        visited[current] = 1;
    }

    return numToString(pointingTo, nums[0].length());
}
