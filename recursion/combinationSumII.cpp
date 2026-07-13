/*40. Combination Sum II
Solved
Medium
Topics
premium lock icon
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

class Solution {
    void subsum(int ind,vector<int>& a,int k,vector<vector<int>>& ans,vector<int>& ds)
    {
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<a.size();i++)
        {
            if(i>ind && a[i]==a[i-1])
                continue;
            if(a[i]>k)
                break;
            ds.push_back(a[i]);
            subsum(i+1,a,k-a[i],ans,ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        subsum(0,candidates,target,ans,ds);
        return ans;
    }
};