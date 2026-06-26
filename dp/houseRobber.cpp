/*198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.*/

//RECURSIVE
class Solution {
    int robHelp(int n,vector<int>& a)
    {
        if(n==0)
            return a[n];
        if(n<0)
            return 0;
        int pick=a[n]+robHelp(n-2,a);
        int notPick=robHelp(n-1,a);
        return max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        return robHelp(n-1,nums);
    }
};


//MEMOIZATION
class Solution {
    int robHelp(int n,vector<int>& a,vector<int>& dp)
    {
        if(n==0)
            return a[n];
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int pick=a[n]+robHelp(n-2,a,dp);
        int notPick=robHelp(n-1,a,dp);
        return dp[n]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return robHelp(n-1,nums,dp);
    }
};

//TABULATION
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};

//SPACE OPTIMIZED
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int pick=nums[i]+prev2;
            int notPick=prev1;
            int cur=max(pick,notPick);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};