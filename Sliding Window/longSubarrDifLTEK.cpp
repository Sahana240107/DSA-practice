/*
Code
Testcase
Testcase
Test Result
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> dmax,dmin;
        int left=0,n=nums.size();
        int i=0,len=0;
        while(left<=i && i<n)
        {
            if(!dmax.empty() && dmax.front()<left)
                dmax.pop_front();
            if(!dmin.empty() && dmin.front()<left)
                dmin.pop_front();
            while(!dmax.empty() && nums[dmax.back()]<=nums[i])
                dmax.pop_back();
            while(!dmin.empty() && nums[dmin.back()]>=nums[i])
                dmin.pop_back();
            dmax.push_back(i);
            dmin.push_back(i);
            if(nums[dmax.front()]-nums[dmin.front()]<=limit)
            {
                len=max(len,i-left+1);
                i++;
            }
            else
                left++;
        }
        return len;
    }
};