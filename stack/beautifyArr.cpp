/*Given an array of negative and non-negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] are either negative or non-negative. And you can do the following operation any number of times until the array becomes beautiful.

If two adjacent integers are different i.e. one of them is negative and other is non-negative, remove them.
Return the beautiful array after performing the above operation.

Note:An empty array is also a beautiful array. There can be many adjacent integers which are different as stated above. So remove different adjacent integers as described above from left to right.

Example 1:

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.
Example 2:

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. */
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && (st.top()>=0 && arr[i]<0 || st.top()<0 && arr[i]>=0))
                st.pop();
            else
                st.push(arr[i]);
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1;i>=0;i--)
        {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};