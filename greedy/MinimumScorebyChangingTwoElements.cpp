/*2567. Minimum Score by Changing Two Elements
You are given an integer array nums.

The low score of nums is the minimum absolute difference between any two integers.
The high score of nums is the maximum absolute difference between any two integers.
The score of nums is the sum of the high and low scores.
Return the minimum score after changing two elements of nums.

Example 1:

Input: nums = [1,4,7,8,5]

Output: 3

Explanation:

Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
The low score is the minimum absolute difference: |6 - 6| = 0.
The high score is the maximum absolute difference: |8 - 5| = 3.
The sum of high and low score is 3.
Example 2:

Input: nums = [1,4,3]

Output: 0

Explanation:

Change nums[1] and nums[2] to 1 so that nums becomes [1,1,1].
The sum of maximum absolute difference and minimum absolute difference is 0.
 
Constraints:

3 <= nums.length <= 105
1 <= nums[i] <= 109
*/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)
            return 0;
        sort(nums.begin(),nums.end());
        return min({
            nums[n-1]-nums[2],
            nums[n-2]-nums[1],
            nums[n-3]-nums[0]
        });
    }
};

//Optimized without sorting
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)
            return 0;
        int l1=INT_MIN,l2=INT_MIN,l3=INT_MIN,s1=INT_MAX,s2=INT_MAX,s3=INT_MAX;
        for(int n:nums)
        {
            if(n<s1)
            {
                s3=s2;
                s2=s1;
                s1=n;
            }
            else if(n<s2)
            {
                s3=s2;
                s2=n;
            }
            else if(n<s3)
                s3=n;
            if(n>l1)
            {
                l3=l2;
                l2=l1;
                l1=n;
            }
            else if(n>l2)
            {
                l3=l2;
                l2=n;
            }
            else if(n>l3)
                l3=n;
        }
        return min({l1-s3,l2-s2,l3-s1});
    }
};