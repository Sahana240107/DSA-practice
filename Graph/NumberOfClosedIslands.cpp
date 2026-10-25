/*1254. Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:


Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1*/

//DFS
class Solution {
    bool dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m)
            return false;
        if(grid[r][c]==1 || visited[r][c])
            return true;
        visited[r][c]=true;
        bool isClosed=true;
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(!dfs(nr,nc,grid,visited))
                isClosed=false;
        }
        return isClosed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0 && !visited[i][j] && dfs(i,j,grid,visited))
                    count++;
            }
        }
        return count;
    }
};