/*907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
*/
class Solution {
    vector<int> findnse(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=findnse(arr);
        vector<int> pse=findpse(arr);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=left*right*1LL;
            int val=(freq*arr[i]*1LL)%mod;
            sum=(sum+val)%mod;
        }        
        return (int)sum%mod;
    }
};