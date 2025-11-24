/*Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].

Examples:

Input: arr[] = [1, 2, 3, 7, 5], target = 12
Output: [2, 4]
Explanation: The sum of elements from 2nd to 4th position is 12.*/
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        long sum=0;
        int left=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            while(sum>target && left<=i)//remove elements from front
            {
                sum-=arr[left];
                left++;
            }
            if(sum==target)
            {
                return {left+1,i+1};
            }
        }
        return {-1};
    }
};