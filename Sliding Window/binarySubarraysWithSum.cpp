/*930. Binary Subarrays With Sum
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefix;
        int count=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==goal)
                count++;
            if(sum>=goal && prefix.find(sum-goal)!=prefix.end())
            {
                count+=prefix[sum-goal];
            }
            prefix[sum]++;
        }
        return count;
    }
};


//Variable silding window

//atmost(goal)-atmost(goal-1)
class Solution {
public:
    int atmostKsum(vector<int>& nums,int k)
    {
        if(k<0)
            return 0;
        int left=0,count=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>k)
            {
                sum-=nums[left];
                left++;
            }
            count+=(i-left+1);
        }
        return count;
    }    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostKsum(nums,goal)-atmostKsum(nums,goal-1);
    }
};