/*410. Split Array Largest Sum
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.*/
class Solution {
    int maxElement(vector<int>& a)
    {
        int maxi=a[0];
        for(int i=1;i<a.size();i++)
        {
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
    int sumArr(vector<int>& a)
    {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        return sum;
    }
    int countSubarr(int maxi,vector<int> a)
    {
        int subarr=1,val=0;
        for(int i=0;i<a.size();i++)
        {
            if(val+a[i]<=maxi)
                val+=a[i];
            else
            {
                subarr++;
                val=a[i];
            }
        }
        return subarr;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k)
            return -1;
        int low=maxElement(nums);
        int high=sumArr(nums);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(countSubarr(mid,nums)>k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};