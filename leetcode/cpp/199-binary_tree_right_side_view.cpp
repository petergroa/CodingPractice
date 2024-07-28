/* 199. Binary Tree Right Side View
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to bottom
 * 
 * Example 1:
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 * Example 2:
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 */
#include<vector>
#include<queue>

std::vector<int> rightSideView(TreeNode* root) {
  std::vector<int> v;
  if (root == 0) return v;

  std::queue<TreeNode*> q;
  int qs;

  q.push(root);
  while(!q.empty()) {
    TreeNode* last = 0;
    do {
      if (q.front() != 0) {
        v.push_back(q.front()->val);
        last = q.front();
      } else q.pop();
    } while(!q.empty() && last == 0);
    qs = qs.size();
    for (int i = 0; i < qs; i++) {
      if (q.front() != 0) {
        q.push(q.front()->right);
        q.push(q.front()->left);
      }
      q.pop();
    }
  }
  return v;
}
