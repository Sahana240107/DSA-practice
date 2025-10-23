/*Given a sorted array arr consisting of 0s and 1s. The task is to find the index (0-based indexing) of the first 1 in the given array.

NOTE: If one is not present then, return -1.

Examples :

Input : arr[] = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1]
Output : 6
Explanation: The index of first 1 in the array is 6.
Input : arr[] = [0, 0, 0, 0]
Output : -1
Explanation: 1's are not present in the array.
*/
class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        // Your code goes here
        int low=0,high=arr.size()-1,first=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==1)
            {
                first=mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        return first;
    }
};