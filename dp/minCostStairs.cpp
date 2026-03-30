/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/


//Recursion
int minCost(int i,vector<int>& cost)
{
    if(i<=0)
        return 0;
    int oneStep=minCost(i-1,cost)+cost[i-1];
    int twoStep=minCost(i-2,cost)+cost[i-2];
    return min(oneStep,twoStep);
}


//Memoization
class Solution {
public:
    int minCost(int i, vector<int>& cost, vector<int>& dp)
    {
        if(i<=0)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int oneStep = minCost(i-1, cost, dp) + cost[i-1];
        int twoStep = minCost(i-2, cost, dp) + cost[i-2];

        return dp[i] = min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return minCost(n, cost, dp);
    }
};


//Tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            int oneStep=dp[i-1]+cost[i-1];
            int twoStep=dp[i-2]+cost[i-2];
            dp[i]=min(oneStep,twoStep);
        }
        return dp[n];
    }
};


//Optimal
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2=0,prev1=0,cur=0,n=cost.size();
        for(int i=2;i<=n;i++)
        {
            int oneStep=prev1+cost[i-1];
            int twoStep=prev2+cost[i-2];
            cur=min(oneStep,twoStep);
            prev2=prev1;
            prev1=cur;
        }
        return cur;
    }
};