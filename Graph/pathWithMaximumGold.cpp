/*
1219. Path with Maximum Gold
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.*/
class Solution {
    void dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<bool>>& visited,int sum,int& maxi)
    {
        int n=grid.size(),m=grid[0].size();
        visited[sr][sc]=true;
        sum+=grid[sr][sc];
        maxi=max(maxi,sum);
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int r=sr+dr[i];
            int c=sc+dc[i];
            if(r<n && r>=0 && c<m && c>=0 && !visited[r][c] && grid[r][c]!=0)
            {
                dfs(r,c,grid,visited,sum,maxi);
            }
        }
        visited[sr][sc]=false;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    dfs(i,j,grid,visited,0,maxi);
                }
            }
        }
        return maxi;
    }
};