/*Given an array arr[] of integers. The problem is finding the longest contiguous subarray's length such that every element is strictly greater than its previous element in the same subarray.

Examples:

Input: arr[] = [5, 6, 3, 5, 7, 8, 9, 1, 2]
Output: 5
Explanation: here the subarray arr[2:6] = [3, 5, 7, 8, 9] is longest subarray to follow strictly increasing order.*/

class Solution {
  public:
    // Function to find the length of longest increasing subarray
    int lenOfLongIncSubArr(vector<int> &arr) {
        int maxi=0,len=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]<=arr[i-1])
                len=0;
            else
            {
                len++;
                maxi=max(maxi,len);
            }
        }
        return maxi+1;
    }
};