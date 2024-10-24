/* 2583. Kth Largest Sum in a Binary Tree
 * You are given the root of a binary tree and a positive integer k.
 * 
 * The level sum in the tree is the sum of the values of the nodes that are on
 * the same level.
 * 
 * Return the kth largest level sum in the tree (not necessarily distinct). If
 * there are fewer than k levels in the tree, return -1.
 * 
 * Note that two nodes are on the same level if they have the same distance
 * from the root.
 * 
 * Example 1:
 * Input: root = [5,8,9,2,1,3,7,4,6], k = 2
 * Output: 13
 * Explanation: The level sums are the following:
 * - Level 1: 5.
 * - Level 2: 8 + 9 = 17.
 * - Level 3: 2 + 1 + 3 + 7 = 13.
 * - Level 4: 4 + 6 = 10.
 * The 2nd largest level sum is 13.
 *
 * Example 2:
 * Input: root = [1,2,null,3], k = 1
 * Output: 3
 * Explanation: The largest level sum is 3.
 * 
 * Constraints:
 * The number of nodes in the tree is n.
 * 2 <= n <= 105
 * 1 <= Node.val <= 106
 * 1 <= k <= n
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<queue>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int depth = 0;
        std::queue<TreeNode*> q = std::queue<TreeNode*>({root});
        std::priority_queue<long long> sums;
        while(!q.empty()){
            int levelSize = q.size();
            long long levelSum = 0;
            for(int i = 0 ; i < levelSize; i++) {
                levelSum += q.front()->val;
                if (q.front()->left != NULL)
                    q.push(q.front()->left);
                if (q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
            }
//            printf("%i %i\n", depth, levelSum);
            depth++;
            sums.push(levelSum);
        }
        if (depth < k) return -1;

        for (int i = 1; i < k; i++) {
//            printf("%i\n", sums.top());
            sums.pop();
        }
        return sums.top();
    }
};
