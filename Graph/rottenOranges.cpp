/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int maxi=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int orange=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                    orange++;
                else
                    visited[i][j]=0;
            }
        }
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            maxi=max(maxi,t);
            int dr[]={0,0,-1,1};
            int dc[]={-1,1,0,0};
            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !visited[nr][nc])
                {
                    q.push({{nr,nc},t+1});
                    orange--;
                    visited[nr][nc]=2;
                }
            }
        }
        if(orange!=0)
            return -1;
        return maxi;
    }
};