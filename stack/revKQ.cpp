/*Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Input: k = 3, queue[] = [1, 2, 3, 4, 5]
Output: 3 2 1 4 5
Explanation: After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5.
*/
class Solution {
  public:
    queue<int> modifyQueue(queue<int> &q, int k) {
        // code here
        int ind=q.size()-k;
        stack<int> st;
        while(k>0 && !q.empty())
        {
            st.push(q.front());
            q.pop();
            k--;
        }
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        while(ind>0 && !q.empty())
        {
            q.push(q.front());
            q.pop();
            ind--;
        }
        return q;
        
    }
};
