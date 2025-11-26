/*Given a stack s, delete the middle element of the stack without using any additional data structure.

Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

Note: The output shown by the compiler is the stack from top to bottom.

Examples:

Input: s = [10, 20, 30, 40, 50]
Output: [10, 20, 40, 50]
Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like {10 20 40 50}.
Input: s = [10, 20, 30, 40]
Output: [10, 30, 40]
Explanation: The bottom-most element will be 10 and the top-most element will be 40. Middle element will be element at index 2 from bottom, which is 20. Deleting 20, stack will look like {10 30 40}.
*/
// User function template for C++

class Solution {
  public:
    void deleteHelper(stack<int>&st,int current,int mid)
    {
        if(current==mid)
        {
            st.pop();
            return;
        }
        int top=st.top();
        st.pop();
        deleteHelper(st,current+1,mid);
        st.push(top);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int mid=(s.size()+1)/2;
        int midFromTop=s.size()-mid+1;
        deleteHelper(s,1,midFromTop);
    }
};