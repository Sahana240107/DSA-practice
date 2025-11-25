/*Given an array arr[] and a number k. The task is to delete k elements that are smaller than the next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than the next because the next element is deleted.

Examples:

Input: arr[] = [20, 10, 25, 30, 40], k = 2
Output: [25, 30, 40]
Explanation: First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20 because 25 is moved next to it and it also starts following the condition.
*/
class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        // complete the function
        stack<int> st;
        int n=arr.size();
        if(k>n)
            return {};
        for(int i=0;i<n;i++)
        {
            while(k>0 && !st.empty() && st.top()<arr[i])
            {
                st.pop();
                k--;
            }
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