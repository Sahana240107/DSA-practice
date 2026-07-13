/*Subsequence with Sum K
Difficulty: MediumAccuracy: 40.26%Submissions: 85K+Points: 4Average Time: 30m
Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals to k.

Examples:

Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
Output: true
Explanation: Subsequences like [2, 6], [1, 7] sum upto 8
Input: arr = [2, 3, 5, 7, 9], k = 100. 
Output: false
Explanation: No subsequence can sum upto 100
*/
class Solution {
    bool subSum(int i,vector<int> a,int k,int sum)
    {
        if(sum>k)
            return false;
        if(i==a.size())
        {
            if(sum==k)
                return true;
            else
                return false;
        }
        sum+=a[i];
        if(subSum(i+1,a,k,sum))
            return true;
        sum-=a[i];
        if(subSum(i+1,a,k,sum))
            return true;
        return false;
    }
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        return subSum(0,arr,k,0);
    }
};