/*46. Permutations
Medium
Topics
premium lock icon
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]*/
class Solution {
    void helper(vector<int>& ds,vector<int>& a,vector<vector<int>>& ans,vector<int>& visited)
    {
        if(ds.size()==a.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<a.size();i++)
        {
            if(!visited[i])
            {
                ds.push_back(a[i]);
                visited[i]=1;
                helper(ds,a,ans,visited);
                visited[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> visited(nums.size(),0);
        helper(ds,nums,ans,visited);
        return ans;
    }
};


//optimal
class Solution {
    void helper(int ind,vector<int>& a,vector<vector<int>>& ans)
    {
        if(ind==a.size())
        {
            ans.push_back(a);
            return;
        }
        for(int i=ind;i<a.size();i++)
        {
            swap(a[ind],a[i]);
            helper(ind+1,a,ans);
            swap(a[ind],a[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;
    }
};