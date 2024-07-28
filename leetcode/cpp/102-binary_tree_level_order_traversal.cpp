/* 102. Binary Tree Level Order Traversal
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 * 
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 *
 * Example 2:
 * Input: root = [1]
 * Output: [[1]]
 *
 * Example 3:
 * Input: root = []
 * Output: []
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 */
#include<vector>
#include<queue>
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> vv = std::vector<std::vector<int>>();
  if (root == 0) return vv;
  std::queue<TreeNode*> q;
  q.push(root);
  int qs;
  while(!q.empty()) {
    std::vector<int> v = std::vector<int>(q.size());
    qs = q.size();
    for (int i = 0; i < qs; i++) {
      v[i] = q.front()->val;
      if (q.front()->left != 0) q.push(q.front()->left);
      if (q.front()->right != 0) q.push(q.front()->right);

      q.pop();
    }
    vv.push_back(v);
  }
  return vv;
}
