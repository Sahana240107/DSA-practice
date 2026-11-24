/*3411. Maximum Subarray With Equal Products

You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

prod(arr) is the product of all elements of arr.
gcd(arr) is the GCD of all elements of arr.
lcm(arr) is the LCM of all elements of arr.
Return the length of the longest product equivalent subarray of nums.

Example 1:

Input: nums = [1,2,1,2,1,1,1]

Output: 5

Explanation: 

The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

Example 2:

Input: nums = [2,3,4,5,6]

Output: 3

Explanation: 

The longest product equivalent subarray is [3, 4, 5].

Example 3:

Input: nums = [1,2,3,1,4,5,1]

Output: 5
Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 10*/

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            long long prod=nums[i];
            long long gcdVal=nums[i];
            long long lcmVal=nums[i];
            for(int j=i+1;j<n;j++)
            {
                prod=prod*nums[j];
                gcdVal=gcd(gcdVal,nums[j]);
                lcmVal=lcm(lcmVal,nums[j]);
                if(prod>gcdVal*lcmVal)
                    break;
                if(prod==gcdVal*lcmVal)
                    res=max(res,j-i+1);
            }
        }
        return res;
    }
};