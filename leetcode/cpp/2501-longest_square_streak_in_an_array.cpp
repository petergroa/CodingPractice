/* 2501. Longest Square Streak in an Array
 *
 * You are given an integer array nums. A subsequence of nums is called a
 * square streak if:
 * 
 * The length of the subsequence is at least 2, and
 * after sorting the subsequence, each element (except the first element) is
 * the square of the previous number.
 * Return the length of the longest square streak in nums, or return -1 if
 * there is no square streak.
 * 
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 * 
 * Example 1:
 * Input: nums = [4,3,6,16,8,2]
 * Output: 3
 * Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
 * - 4 = 2 * 2.
 * - 16 = 4 * 4.
 * Therefore, [4,16,2] is a square streak.
 * It can be shown that every subsequence of length 4 is not a square streak.
 *
 * Example 2:
 * Input: nums = [2,3,5,6,7]
 * Output: -1
 * Explanation: There is no square streak in nums so return -1.
 * 
 * Constraints:
 * 2 <= nums.length <= 105
 * 2 <= nums[i] <= 105
 */
#include<vector>

size_t binarySearch(std::vector<int>& a, size_t start, size_t end, int val) {
//    printf("(%zu,%zu,", start, end);
    if (start > end) return 0;
    size_t mid = start+(end-start)/2;
//    printf("%zu) ", mid);
    if (a[mid] == val) return mid;
    if (a[mid] > val)
        return binarySearch(a, start, mid-1, val);
    return binarySearch(a, mid+1, end, val);
}

int recursiveLSS(std::vector<int>& nums, size_t index, std::vector<int>& seqDp,
std::vector<int>& maxDp) {
//    printf("RLSS [%zu]%i -> ", index, nums[index]);
    if (index == nums.size()) return 0;
    if (maxDp[index]) return maxDp[index];

    // no need to calc square, it will overflow
    size_t next = (nums[index] <= 46340)?
        binarySearch(nums, index+1, nums.size()-1, nums[index]*nums[index])
        :0;
//    printf("next=%zu ", next);

    if (next) {
        recursiveLSS(nums, next, seqDp, maxDp);
        seqDp[index] = 1+seqDp[next];
        maxDp[index] = max(seqDp[index], maxDp[next]);
    } else {
        seqDp[index] = 1;
        maxDp[index] = 1;
    }
//    printf("sedDp[%zu]=%i maxDp=%i\n", index, seqDp[index], maxDp[index]);

    // Last item
    if(index == nums.size()-1) return maxDp[index];
    // Check if skipping would be better
    maxDp[index] = max(
        maxDp[index],
        maxDp[index+1]?
            maxDp[index+1]:
            recursiveLSS(nums, index+1, seqDp, maxDp));
    return maxDp[index];
}

int longestSquareStreak(std::vector<int>& nums) {
    std::vector<int> seqDp = std::vector<int>(nums.size(), 0);
    std::vector<int> maxDp = std::vector<int>(nums.size(), 0);
    sort(nums.begin(), nums.end());
    int res = recursiveLSS(nums, 0, seqDp, maxDp);
    return (res > 1)? res : -1;
}
