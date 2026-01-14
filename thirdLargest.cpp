/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
       if(nums.size()==0)
            return -1;
        long long first=LLONG_MIN,second=LLONG_MIN,third=LLONG_MIN;
        int count=0;
        for(int x:nums)
        {
            if(x>first)
            {
                third=second;
                second=first;
                first=x;
                count++;
            }
            else if(x<first && x>second)
            {
                third=second;
                second=x;
                count++;
            }
            else if(x<second && x>third)
            {
                third=x;
                count++;
            }
        } 
        return count<3?first:(int)third;
    }
};