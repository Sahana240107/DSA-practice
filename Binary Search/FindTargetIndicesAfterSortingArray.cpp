/*2089. Find Target Indices After Sorting Array

You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

Example 1:

Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
Example 2:

Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.
Example 3:

Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.*/

//Binary Search
class Solution {
    int first(vector<int>&nums, int target){
        int low = 0 ; 
        int high = nums.size()-1;
        int ans = -1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(nums[mid]== target){
                 ans = mid;
                 high = mid -1;
            }else if(nums[mid]>target){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    };
    int last(vector<int>&nums, int target){
        int low = 0 ; 
        int high = nums.size()-1;
        int ans = -1;
        while(low <=high){
            int mid = low + (high-low)/2;
            if(nums[mid]== target){
                 ans = mid;
                 low = mid + 1;
            }else if(nums[mid]>target){
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    };
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>arr = nums;
        sort(arr.begin(), arr.end());
        int f = first(arr, target);
        int l = last(arr, target);
        vector<int> res;
        if (f == -1) return res;  
        for(int i = f; i<=l;i++){
            res.push_back(i);
        }
        return res;
    }

};

//O(n) optimized
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller=0,count=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<target)
                smaller++;
            else if(nums[i]==target)
                count++;
        }
        int i=smaller;
        vector<int> ans;
        while(count>0)
        {
            ans.push_back(i);
            i++;
            count--;
        }
        return ans;
    }
};