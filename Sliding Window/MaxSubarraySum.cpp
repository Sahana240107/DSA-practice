/*Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.*/
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        long maxSum=0,subSum=0;
        for(int i=0;i<k;i++)
        {
            subSum+=arr[i];
        }
        maxSum=subSum;
        for(int i=k;i<arr.size();i++)
        {
            subSum+=arr[i]-arr[i-k];
            maxSum=max(maxSum,subSum);
        }
        return maxSum;
    }
};