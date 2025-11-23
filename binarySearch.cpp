/*Given a sorted array arr[] and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.
 If k doesn't exist in arr[] return -1. 
Note: If multiple occurrences are there, please return the smallest index.
Examples:
Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.*/
class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int low=0,high=arr.size()-1,mid,res=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(arr[mid]==k)
            {
                res=mid;
                high=mid-1;//will check for first occurrence
            }
            else if(arr[mid]<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
        
    }
};