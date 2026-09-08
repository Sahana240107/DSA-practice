/*343. Integer Break
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                dp[i]=max(dp[i],j*(i-j));
                dp[i]=max(dp[i],j*dp[i-j]);
            }
        }
        return dp[n];
    }
};