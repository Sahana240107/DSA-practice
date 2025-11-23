/*Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_count=0,max1=0,start=0;
        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==0)
                zero_count++;
            while(zero_count>k)
            {
                if(nums[start]==0)
                    zero_count--;
                start++;
            }
            max1=max(max1,end-start+1);
        }
        return max1;
    }
};