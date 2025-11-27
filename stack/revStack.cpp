/*You are given a stack st[]. You have to reverse the stack.

Examples:

Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

*/
class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        queue<int> q;
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        while(!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
    }
};