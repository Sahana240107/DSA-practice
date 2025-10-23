/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/
class Solution {
    int findFirst(vector<int>& num,int target)
    {
        int low=0,high=num.size()-1,first=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(num[mid]==target)
            {
                first=mid;
                high=mid-1;
            }
            else if(num[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return first;
    }
    int findLast(vector<int>& num,int target)
    {
        int low=0,high=num.size()-1,last=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(num[mid]==target)
            {
                last=mid;
                low=mid+1;
            }
            else if(num[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirst(nums,target);
        int last=findLast(nums,target);
        return {first,last};
    }
};