/*1020. Number of Enclaves
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.*/

class Solution {
    void dfs(int r,int c,vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        grid[r][c]=-1;
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                dfs(nr,nc,grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
                dfs(0,j,grid);
            if(grid[n-1][j]==1)
                dfs(n-1,j,grid);
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                dfs(i,0,grid);
            if(grid[i][m-1]==1)
                dfs(i,m-1,grid);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};