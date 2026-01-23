/*Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the answer fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suf=1,maxi=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pre==0)
                pre=1;
            if(suf==0)
                suf=1;
            pre=pre*nums[i];
            suf=suf*nums[n-i-1];
            maxi=max(maxi,max(pre,suf));
        }
        return maxi;
    }
};