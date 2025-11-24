/*Given an array arr[] of integers, count the number of subarrays in arr[] which are strictly increasing with size greater or equal to 2. A subarray is a contiguous part of array. A subarray is strictly increasing if each element is greater then it's previous element if it exists.

Examples:

Input: arr[] = [1, 3, 3, 2, 3, 5]
Output: 4
Explanation: Increasing Subarrays are : arr[0,1], arr[3,4], arr[3,5], arr[4,5].
*/
class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int count=0,first=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<=arr[i-1])
                first=i;
            else
                count++;
            if(first<i-1)
                count+=(i-first-1);
        }
        return count;
    }
};
