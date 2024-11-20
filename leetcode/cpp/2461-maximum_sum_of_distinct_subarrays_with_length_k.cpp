/* 2461. Maximum Sum of Distinct Subarrays With Length K
 * You are given an integer array nums and an integer k. Find the maximum
 * subarray sum of all the subarrays of nums that meet the following
 * conditions:
 * 
 * The length of the subarray is k, and
 * All the elements of the subarray are distinct.
 * Return the maximum subarray sum of all the subarrays that meet the
 * conditions. If no subarray meets the conditions, return 0.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 *  
 * 
 * Example 1:
 * Input: nums = [1,5,4,2,9,9,9], k = 3
 * Output: 15
 * Explanation: The subarrays of nums with length 3 are:
 * - [1,5,4] which meets the requirements and has a sum of 10.
 * - [5,4,2] which meets the requirements and has a sum of 11.
 * - [4,2,9] which meets the requirements and has a sum of 15.
 * - [2,9,9] which does not meet the requirements because the element 9 is
 *   repeated.
 * - [9,9,9] which does not meet the requirements because the element 9 is
 *   repeated.
 * We return 15 because it is the maximum subarray sum of all the subarrays
 * that meet the conditions
 *
 * Example 2:
 * Input: nums = [4,4,4], k = 3
 * Output: 0
 * Explanation: The subarrays of nums with length 3 are:
 * - [4,4,4] which does not meet the requirements because the element 4 is
 *   repeated.
 * We return 0 because no subarrays meet the conditions.
 *  
 * 
 * Constraints:
 * 
 * 1 <= k <= nums.length <= 105
 * 1 <= nums[i] <= 105
 */
// 1 5 4 4 5 6
// 1 5 -> (6)0
// 1   4 -> (10) 10
//   5 4 4 -> (X) 10
//       4 5 -> (9) 10
//       4 5 6 -> ()
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        bitset<100001> visited;
        long long max = 0, current = 0;
        int back = 0, front = 0;

        while (front < nums.size()) {
//            printf("%i %i dis%i (%i)\n", nums[back], nums[front], front-back, current);
            if (visited[nums[front]-1]) {
//                printf("Erase: ");
                while(nums[back] != nums[front]) {
//                    printf("%i ", nums[back]);
                    visited[nums[back]-1] = 0;
                    current -= nums[back];
                    back++;
                }
//                printf("%i\n", nums[back]);
                visited[nums[back]-1] = 0;
                current -= nums[back];
                back++;
            }
            visited[nums[front]-1] = 1;
            current += nums[front];

            if (front-back==k-1) {
//                printf("Update [%i %i] current = %i, max = %i\n", nums[back], nums[front], current, max);
                max = std::max(current, max);
                visited[nums[back]-1] = 0;
                current -= nums[back];
                back++;
            }

            front++;
        }

        return max;
    }
};
