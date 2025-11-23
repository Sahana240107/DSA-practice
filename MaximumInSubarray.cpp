/*Given an array arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. Return an array of maximum values corresponding to each contiguous subarray.

Examples:

Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output: [3, 3, 4, 5, 5, 5, 6]
Explanation: 
1st contiguous subarray [1, 2, 3], max = 3
2nd contiguous subarray [2, 3, 1], max = 3
3rd contiguous subarray [3, 1, 4], max = 4
4th contiguous subarray [1, 4, 5], max = 5
5th contiguous subarray [4, 5, 2], max = 5
6th contiguous subarray [5, 2, 3], max = 5
7th contiguous subarray [2, 3, 6], max = 6*/
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<arr.size();i++)
        {
            if(!dq.empty() && dq.front()<=i-k)//remove index out of window
            {
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()]<=arr[i])
            {
                dq.pop_back();//remove elements in back that is smaller than arr[i] becoz ot cant be max
            }
            dq.push_back(i);
            if(i>=k-1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};