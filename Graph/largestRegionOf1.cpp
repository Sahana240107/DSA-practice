/*argest Region of 1's in a Binary Matrix
Difficulty: MediumAccuracy: 50.83%Submissions: 76K+Points: 4Average Time: 20m
Given a grid of dimensions nxm containing 0's and 1's. Find the count of 1's in the largest region of 1's. A region of 1's is a group of 1's where two 1s can be adjacent to each other in any of the 8 directions ( 2 horizontal, 2 vertical and 4 diagonal). 

Examples :

Input: grid[][] = [[1, 1, 1, 0], [0, 0, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0]]
Output: 5
Explanation: 

The largest region has five 1s 
Input: grid[][] = [[0,1]]
Output: 1
Explanation: The largest region of 1's is 1.*/
class Solution {
    void dfs(int r,int c,vector<vector<bool>>& visited,vector<vector<int>>& grid,int& ones)
    {
        ones++;
        visited[r][c]=true;
        int n=grid.size(),m=grid[0].size();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nr=r+i;
                int nc=c+j;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !visited[nr][nc])
                    dfs(nr,nc,visited,grid,ones);
            }
        }
    }
  public:
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int maxi=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    int ones=0;
                    dfs(i,j,visited,grid,ones);
                    maxi=max(maxi,ones);
                }
            }
        }
        return maxi;
    }
};