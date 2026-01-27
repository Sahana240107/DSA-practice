/*Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,mini=INT_MAX,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                mini=min(mini,i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return mini==INT_MAX?0:mini;
    }
};

//With negatives

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }
        deque<int> dq;
        int mini=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            while(!dq.empty() && pre[i]-pre[dq.front()]>=k)
            {
                mini=min(mini,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && pre[i]<=pre[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return mini==INT_MAX?-1:mini;
    }
};