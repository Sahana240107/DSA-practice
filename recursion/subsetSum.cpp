/*Subset Sum : Sum of all Subsets

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order*/

class Solution {
public:
    void findSums(int ind, int sum, vector<int>& arr, vector<int>& sums) {
        if (ind == arr.size()) {
            sums.push_back(sum);
            return;
        }

        // Include current element
        findSums(ind + 1, sum + arr[index], arr, sums);

        // Exclude current element
        findSums(ind + 1, sum, arr, sums);
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums;
        findSums(0, 0, arr, sums);
        sort(sums.begin(), sums.end()); 
        return sums;
    }
};

/*78. Subsets
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
    void helper(int ind,vector<int>& sum,vector<int>& a,vector<vector<int>>& sums)
    {
        if(ind==a.size())
        {
            sums.push_back(sum);
            return;
        }
        sum.push_back(a[ind]);
        helper(ind+1,sum,a,sums);
        sum.pop_back();
        helper(ind+1,sum,a,sums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sums;
        vector<int> sum;
        helper(0,sum,nums,sums);
        return sums;
    }
};