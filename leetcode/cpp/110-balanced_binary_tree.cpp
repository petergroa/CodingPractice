/* 110. Balanced Binary Tree
 * Given a binary tree, determine if it is height-balanced.
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 * Example 2:
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 * Example 3:
 * Input: root = []
 * Output: true
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [0, 5000].
 * -104 <= Node.val <= 104
 */

int dfs(TreeNode *root, bool &balanced) {
  if (root == NULL) return -1;
  int l = dfs(root->left, balanced);
  int r = dfs(root-> right, balanced);
  if (abs(l-r) > 1) {
    balanced = false;
    return 0;
  }

  return 1 + max(l, r);
}

bool isBalanced(TreeNode *root) {
  if (root == NULL) return true;
  bool balanced = true;
  int l = dfs(root->left, balanced);
  int r = dfs(root->right, balanced);
  return balanced && (abs(l-r) <= 1);
}
