/*Given a sorted array, arr[] containing only 0s and 1s, find the transition point, i.e., the first index where 1 was observed, and before that, only 0 was observed.  
If arr does not have any 1, return -1. If array does not have any 0, return 0.
Examples:
Input: arr[] = [0, 0, 0, 1, 1]
Output: 3
Explanation: index 3 is the transition point where 1 begins.*/
class Solution {
  public:
    int transitionPoint(vector<int>& arr) {
        int low=0,high=arr.size()-1,res=-1,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(arr[mid]==1)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};