/* Leetcode 1642.
 * You are given an integer array heights representing the heights of buildings,
 * some bricks, and some ladders.
 * You start your journey from building 0 and move to the next building by
 * possibly using bricks or ladders.
 * While moving from building i to building i+1 (0-indexed),
 *     - If the current building's height is greater than or equal to the next
 *     building's height, you do not need a ladder or bricks.
 *     - If the current building's height is less than the next building's
 *     height, you can either use one ladder or (h[i+1] - h[i]) bricks.
 * Return the furthest building index (0-indexed) you can reach if you use the
 * given ladders and bricks optimally.
 */
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int>::iterator itb = heights.begin(), itf = heights.begin() + 1;
        // make heap
        vector<int> difs;
        make_heap(difs.begin(), difs.end());
        
        // floor diff
        int delta;
        while(itf != heights.end()) {
            if (*itb < *itf) {
                // Calc difference
                delta = *itf-*itb;
                // Add to heap
                difs.push_back(delta);
                push_heap(difs.begin(), difs.end());
                // Check if there are enough bricks
                if (delta <= bricks) bricks -= delta;   
                // Check if we can use a stair in optimal place
                else if (ladders) {
                    bricks += (difs.front() - delta);
                    // Pop biggest difference
                    pop_heap(difs.begin(), difs.end());
                    difs.pop_back();
                    // Reduce ladders
                    ladders--;
                } else break; // Not enough material
            }
            itf++; itb++;
        }
        
        return itf - heights.begin() - 1;
    }
};
