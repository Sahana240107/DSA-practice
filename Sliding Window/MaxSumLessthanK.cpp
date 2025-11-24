/*Given an array arr[] of integers and a number x, the task is to find the sum of subarray having a maximum sum less than or equal to the given value of x.

Examples:

Input: arr[] = [1, 2, 3, 4, 5], x = 11 
Output: 10
Explanation: Subarray having maximum sum is [1, 2, 3, 4].
*/
class Solution {
  public:
    long long findMaxSubarraySum(vector<int>& arr, long long x) {
        long long sum=0,maxs=0;
        int maxf=0,maxe=0;
        int first=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            while(sum>x && first<i)
            {
                sum-=arr[first];
                first++;
            }
            if(sum<x && maxs<sum)
            {
                maxs=sum;
                maxf=first;
                maxe=i;
            }
            if(sum==x)
            {
                return sum;
            }
        }
        return maxs;
    }
};
