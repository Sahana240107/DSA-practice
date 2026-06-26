/*213. House Robber II
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.*/
class Solution {
    int robH(vector<int>& nums,int l,int r) {
        int n=r-l+1;
        if(n==1)
            return nums[l];
        int prev2=nums[l];
        int prev1=max(nums[l],nums[l+1]);
        for(int i=l+2;i<=r;i++)
        {
            int pick=nums[i]+prev2;
            int notPick=prev1;
            int cur=max(pick,notPick);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(robH(nums,1,n-1),robH(nums,0,n-2));
    }
};