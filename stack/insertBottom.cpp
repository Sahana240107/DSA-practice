/*You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 

Note: Everywhere in this problem, the bottommost element of the stack is shown first while priniting the stack.

Example 1:

Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.
*/
// User function Template for C++

class Solution {
  public:
    void insertHelper(stack<int>& st,int x)
    {
        if(st.empty())
        {
            st.push(x);
            return;
        }
        int top=st.top();
        st.pop();
        insertHelper(st,x);
        st.push(top);
    }
    stack<int> insertAtBottom(stack<int> st, int x) 
    {
        insertHelper(st,x);
        return st;
    }
};