/*1248. Count Number of Nice Subarrays
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 */
 class Solution {
public:
    int atmostKodd(vector<int>& nums,int k)
    {
        if(k<0)
            return 0;
        int left=0,count=0,odds=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
                odds++;
            while(odds>k)
            {
                if(nums[left]%2!=0)
                    odds--;
                left++;
            }
            count+=(i-left+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostKodd(nums,k)-atmostKodd(nums,k-1);
    }
};