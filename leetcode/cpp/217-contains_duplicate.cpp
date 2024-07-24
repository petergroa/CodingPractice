/*
 * Given an integer array nums, return true if any value appears at least
 * twice in the array, and return false if every element is distinct.
 *
 * int get_bit(int element)
{
    uint byte_index = element/8;
    uint bit_index = element % 8;
    uint bit_mask = ( 1 << bit_index);

    return ((pStatus[byte_index] & bit_mask) != 0);
}

void set_bit (int element)
{
    uint byte_index = element/8;
    uint bit_index = element % 8;
    uint bit_mask = ( 1 << bit_index);

    pStatus[byte_index] |= bit_mask);
}

void clear_bit (int element)
{
    uint byte_index = element/8;
    uint bit_index = element % 8;
    uint bit_mask = ( 1 << bit_index);

    pStatus[byte_index] &= ~bit_mask;
}
 */

// using set 127ms 73.5MB

// sort and iterate 87ms 61.1MB
bool containsDuplicate(vector<int>& nums) {
  if (nums.size() < 2) return false;
  std::sort(nums.begin(), nums.end());

  for(int i = 0; i < nums.size()-1 ; i++) {
    if (nums[i] == nums[i+1]) return true;
  }
  return false;
}

// binary manipulation 49ms 60MB
bool containsDuplicate(vector<int>& nums) {
  char *brray = (char *)calloc( (INT_MAX/4)+1, sizeof(char));
  int index;
  for (int i = 0; i < num.size(); i++) {
    if (nums[i] < 0) index = (nums[i]*-2)+1; // handle all negatives as odd numbers
    else index = nums[i]*2; // all positives are even numbers

    if ((brray[index/8] & (1<<index%8)) != 0) {
      free(brray);
      return true;
    }
    brray[index/8] |= 1<<(index%8);
  }
  free(brray);
  return false;
}
