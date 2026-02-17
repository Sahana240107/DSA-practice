/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[left]<=nums[mid])
            {
                if(nums[left]<=target && nums[mid]>target)
                    right=mid-1;
                else 
                    left=mid+1;
            }
            else
            {
                if(nums[mid]<target && nums[right]>=target)
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};


//Search in rotated sorted array with duplicates 
/*There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)   
                return true;
            if(nums[left]==nums[mid] && nums[mid]==nums[right])
            {
                left++;
                right--;
            }
            else if(nums[left]<=nums[mid])
            {
                if(nums[left]<=target && nums[mid]>target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else
            {
                if(nums[mid]<target && nums[right]>=target)
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return false;
    }
};