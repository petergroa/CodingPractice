/* 1261. Find Elements in a Contaminated Binary Tree
 *
 * Given a binary tree with the following rules:
 * root.val == 0
 * For any treeNode:
 * 1. If treeNode.val has a value x and treeNode.left != null, then
 *    treeNode.left.val == 2 * x + 1
 * 2. If treeNode.val has a value x and treeNode.right != null, then
 *    treeNode.right.val == 2 * x + 2
 * 3. Now the binary tree is contaminated, which means all treeNode.val have
 *    been changed to -1.
 * 
 * Implement the FindElements class:
 * 
 * 1. FindElements(TreeNode* root) Initializes the object with a contaminated
 *    binary tree and recovers it.
 * 2. bool find(int target) Returns true if the target value exists in the
 *    recovered binary tree.
 * 
 * Example 1:
 * Input
 * ["FindElements","find","find"]
 * [[[-1,null,-1]],[1],[2]]
 * Output
 * [null,false,true]
 * Explanation
 * FindElements findElements = new FindElements([-1,null,-1]); 
 * findElements.find(1); // return False 
 * findElements.find(2); // return True 
 *
 * Example 2:
 * Input
 * ["FindElements","find","find","find"]
 * [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
 * Output
 * [null,true,true,false]
 * Explanation
 * FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
 * findElements.find(1); // return True
 * findElements.find(3); // return True
 * findElements.find(5); // return False
 *
 * Example 3:
 * Input
 * ["FindElements","find","find","find","find"]
 * [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
 * Output
 * [null,true,false,false,true]
 * Explanation
 * FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
 * findElements.find(2); // return True
 * findElements.find(3); // return False
 * findElements.find(4); // return False
 * findElements.find(5); // return True
 * 
 * Constraints:
 * TreeNode.val == -1
 * The height of the binary tree is less than or equal to 20
 * The total number of nodes is between [1, 104]
 * Total calls of find() is between [1, 104]
 * 0 <= target <= 106
 */

class FindElements {
 public:
    findElements(TreeNode *root) {
        if (root == nullptr) return;

        // No need to save recovered tree lol
        findElementsRecursive(root, 0);
    }

    bool find(int target) {
        // Contrains specify that there isn´t going to be a target > 10⁶
        return (this->elements[target]);

        // In case prev constrains didn´t exist
//        return (this->elements.contains(target));
    }

 private:
    bitset<1000001> elements;
//    set<int> elements;

    void findElementsRecursive(const TreeNode* node, int nodeIndx) {
        // Will not be asked a bigger number than this
        if (nodeIndx > 1000000) return;

        this->elements[nodeIndx] = 1;

        // if constraint didn´t exist
//        this->elements.insert(nodeIndx);

        if (node->left != nullptr)
            findElementsRecursive(node->left, nodeIndx*2+1);
        if (node->right != nullptr)
            findElementsRecursive(node->right, nodeIndx*2+2);
    }
};
