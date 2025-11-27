/*Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

Note: Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
*/
class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        stack<int> st;
        int n=arr.size();
        vector<int> nge(n);
        for(int i=2*n-1;i>=0;i--)
        {
            int ind=i%n;
            while(!st.empty() && st.top()<=arr[ind])
            {
                st.pop();
            }
            if(i<n)
            {
                nge[i]=(st.empty())?-1:st.top();
            }
            st.push(arr[ind]);
        }
        return nge;
    }
};