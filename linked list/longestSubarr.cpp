/*Given an array arr[], return the length of the longest subarray of non-negative integers.
Note: Subarray here means a continuous part of the array.

Examples:

Input: arr[] = [2, 3, 4, -1, -2, 1, 5, 6, 3]
Output: 4
Explanation: The subarray [ 1, 5, 6, 3] has longest length 4 and contains no negative integers
Input: arr[] = [1, 0, 0, 1, -1, -1, 0, 0, 1, 0]
Output: 4
Explanation: Subarrays [1, 0, 0, 1] and [0, 0, 1, 0] have equal lengths but sum of first one is greater so that will be the output.
*/
class Solution {
    /* Function that returns the longest subarray
       of non-negative integers */
  public:
    int longestSubarry(vector<int>& arr) {
        // write code here
        int len=0,maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>=0)
                len++;
            else
                len=0;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};