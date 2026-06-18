/*1886. Determine Whether Matrix Can Be Obtained By Rotation

Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 */
 class Solution {
    vector<vector<int>> rotate(vector<vector<int>>& mat)
    {
        int n=mat.size();
        vector<vector<int>> ans(n,vector<int> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[j][n-i-1]=mat[i][j];
            }
        }
        return ans;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++)
        {
            if(mat==target)
                return true;
            mat=rotate(mat);
        }
        return false;
    }
};