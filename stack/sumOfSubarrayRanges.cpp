/*2104. Sum of Subarray Ranges
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.*/
class Solution {
    vector<int> findnse(vector<int>& a)
    {
        int n=a.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]>=a[i])
                st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int>& a)
    {
        int n=a.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>a[i])
                st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findnge(vector<int>& a)
    {    
        int n=a.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]<=a[i])
                st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpge(vector<int>& a)
    {
        int n=a.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]<a[i])
                st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    long long subarrayMax(vector<int>& a)
    {
        int n=a.size();
        vector<int> nge=findnge(a);
        vector<int> pge=findpge(a);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int left=i-pge[i];
            int right=nge[i]-i;
            long long freq=left*right*1LL;
            long long val=freq*a[i]*1LL;
            sum+=val;
        }
        return sum;
    }
    long long subarrayMin(vector<int>& a)
    {
        int n=a.size();
        vector<int> nse=findnse(a);
        vector<int> pse=findpse(a);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq=left*right*1LL;
            long long val=freq*a[i]*1LL;
            sum+=val;
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return subarrayMax(nums)-subarrayMin(nums);
    }
};