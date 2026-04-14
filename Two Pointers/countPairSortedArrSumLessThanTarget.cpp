/*Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.

Examples:

Input: arr[] = [2, 3, 5, 7], target = 8
Output: 2
Explanation: The pairs are (2, 3) and (2, 5).
Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], target = 7
Output: 6
Explanation: The pairs are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3) and (2, 4)
*/

// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int i=0,j=arr.size()-1;
        int count=0;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum<target)
            {
                count+=(j-i);
                i++;
            }
            else
                j--;
        }
        return count;
    }
};
