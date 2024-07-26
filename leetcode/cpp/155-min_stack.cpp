/* 155. Min Stack
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * Implement the MinStack class:
 * 1. MinStack() initializes the stack object.
 * 2. void push(int val) pushes the element val onto the stack.
 * 3. void pop() removes the element on the top of the stack.
 * 4. int top() gets the top element of the stack.
 * 5. int getMin() retrieves the minimum element in the stack.
 * You must implement a solution with O(1) time complexity for each function.
 *
 * Example 1:
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * Output
 * [null,null,null,null,-3,null,0,-2]
 */
#include <stack>
class MinStack {
private:
  std::stack<int> stk;
  std::stack<int> mins;
public:
  MinStack() {
    stk = std::stack<int>();
    mins = std::stack<int>();
  }

  void push(int val) {
    stk.push(val);
    if (mins.empty() || val < mins.top()) mins.push(val);
    else mins.push(mins.top());
  }

  void pop() {
    if (stk.empty()) return;
    stk.pop();
    mins.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return mins.top();
  }
};

int main() {
  MinStack ms = MinStack();
  ms.push(-2);
  ms.push(0);
  ms.push(-3);
  ms.getMin();
  ms.pop();
  ms.top();
  ms.getMin();
}
