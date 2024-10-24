/* 2641. Cousins in Binary Tree II
 * Given the root of a binary tree, replace the value of each node in the tree
 * with the sum of all its cousins' values.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth with
 * different parents.
 * 
 * Return the root of the modified tree.
 * 
 * Note that the depth of a node is the number of edges in the path from the
 * root node to it.
 * 
 * Example 1:
 * Input: root = [5,4,9,1,10,null,7]
 * Output: [0,0,0,7,7,null,11]
 * Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
 * - Node with value 5 does not have any cousins so its sum is 0.
 * - Node with value 4 does not have any cousins so its sum is 0.
 * - Node with value 9 does not have any cousins so its sum is 0.
 * - Node with value 1 has a cousin with value 7 so its sum is 7.
 * - Node with value 10 has a cousin with value 7 so its sum is 7.
 * - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
 *
 * Example 2:
 * Input: root = [3,1,2]
 * Output: [0,0,0]
 * Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
 * - Node with value 3 does not have any cousins so its sum is 0.
 * - Node with value 1 does not have any cousins so its sum is 0.
 * - Node with value 2 does not have any cousins so its sum is 0.
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 105].
 * 1 <= Node.val <= 104
 */
#include<iterators>
#include<list>
#include<pair>

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::list<std::pair<TreeNode*, TreeNode*>> childrens = \
            std::list<std::pair<TreeNode*, TreeNode*>>(
                {std::pair<TreeNode*, TreeNode*>(root, NULL)});
        std::list<std::pair<TreeNode*, TreeNode*>>::iterator childrensItr;
        int amountLevel, sum, prev, both;
        while (!childrens.empty()) {
            // Calculate current level
            childrensItr = childrens.begin();
            prev = 0;
            if(childrensItr->first != NULL)
                prev+=childrensItr->first->val;
            if(childrensItr->second != NULL)
                prev+=childrensItr->second->val;
            // Sum of the current cousins
            sum = 0;
            childrensItr++;
            for (; childrensItr != childrens.end(); childrensItr++) {
                if(childrensItr->first != NULL)
                    sum+=childrensItr->first->val;
                if(childrensItr->second != NULL)
                    sum+=childrensItr->second->val;
            }

            // Do another lap to modify values
            // Only iterate throw this level
            // (we are adding the childrend)
            amountLevel = childrens.size();
            childrensItr = childrens.begin();
            for (int i = 0; i < amountLevel; i++) {
                if (i!=0) {
                    both = 0;
                    if (childrensItr->first != NULL)
                        both += childrensItr->first->val;
                    if (childrensItr->second != NULL)
                        both += childrensItr->second->val;
//                    printf("[%i,%i,%i] ", sum, both, prev);
                    sum = sum-both+prev;
                    prev = both;
                }
                if (childrensItr->first != NULL) {
//                    printf("%i->%i | ", childrensItr->first->val, sum);
                    childrensItr->first->val = sum;
                    childrens.push_back(std::pair<TreeNode*, TreeNode*>(
                        childrensItr->first->left,childrensItr->first->right));
                }
                if (childrensItr->second != NULL) {
//                    printf("%i->%i", childrensItr->second->val, sum);
                    childrensItr->second->val = sum;
                    childrens.push_back(std::pair<TreeNode*, TreeNode*>(
                        childrensItr->second->left,childrensItr->second->right));
                }
//                printf(", ");
                childrensItr++;
                childrens.pop_front();
            }
//            printf("\n");
        }
        return root;
    }
};
