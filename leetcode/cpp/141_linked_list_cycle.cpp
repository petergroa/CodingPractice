/* 141. Linked List Cycle
 * Given head, the head of a linked list, determine if the linked list has a
 * cycle in it.
 * 
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is connected
 * to. Note that pos is not passed as a parameter.
 * 
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 1st node (0-indexed).
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 0th node.
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *  
 * 
 * Constraints:
 * 
 * The number of the nodes in the list is in the range [0, 104].
 * -105 <= Node.val <= 105
 * pos is -1 or a valid index in the linked-list.
 *  
 * 
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;

    while (head->next != nullptr) {
        if (head->next->val == INT_MIN) return true;
        head->val = INT_MIN;
        head = head-> next;
    }

    return false;
}

// Or

bool hasCycle2(ListNode *head) {
    int16_t first = static_cast<int16_t>(head), delta = 0;
    bitset<1000000> bitsetTracking;
    bitsetTracking[0] = 1;

    while (head != nullptr && head->next != nullptr) {
        delta = static_cast<int16_t>(head->next)-first;
        if (bitsetTracking[delta] == 1) return true;
        bitsetTracking[delta] = 1;
        head = head->next;
    }
    return false;
}
