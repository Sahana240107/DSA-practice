/*iven a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
Output: 4
Explanation:
The image below shows all the 4 islands in the grid.*/
class Solution {
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>& visited)
    {
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=true;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow=row+i;
                int ncol=col+j;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='L' && !visited[nrow][ncol])
                {
                    dfs(nrow,ncol,grid,visited);
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='L' && !visited[i][j])
                {
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};