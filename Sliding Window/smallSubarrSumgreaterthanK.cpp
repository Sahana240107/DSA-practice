/*Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Examples:

Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: Minimum length subarray is [4, 45, 6]
*/
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        long sum=0;
        int first=0,minlen=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            while(sum>x && first<=i)
            {
                int len=i-first+1;
                minlen=min(len,minlen);
                sum-=arr[first];
                first++;
            }
        }
        if(minlen>arr.size())
            return 0;
        return minlen;
    }
};