/*Number of occurrence
Difficulty: EasyAccuracy: 59.34%Submissions: 401K+Points: 2Average Time: 20m
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.*/
class Solution {
  public:
    int firstOcur(vector<int>& arr,int x)
    {
        int low=0,high=arr.size()-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
    int lastOcur(vector<int>& arr,int x)
    {
        int low=0,high=arr.size()-1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                ans=mid;
                low=mid+1;
            }
            else if(arr[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first=firstOcur(arr,target);
        int last=lastOcur(arr,target);
        if(first==-1 || last==-1)
            return 0;
        else 
            return last-first+1;
    }
};
