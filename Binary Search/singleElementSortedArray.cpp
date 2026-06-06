/*# **Search Single Element in a sorted array**

**Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.Examples

`Input : arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Output: 4
Explanation: Only the number 4 appears once in the array.

Input: arr[] = {1,1,3,5,5}
Output : 3
Explanation: Only the number 3 appears once in the array.`***/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        int low=1,high=nums.size()-2,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            else if(mid%2==1 && nums[mid]!=nums[mid-1] || mid%2==0 && nums[mid]!=nums[mid+1])
                high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }
};