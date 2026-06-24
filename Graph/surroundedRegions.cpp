/*130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

*/

class Solution {
    void dfs(int r,int c,vector<vector<bool>>& visited,vector<vector<char>>& board)
    {
        int n=board.size(),m=board[0].size();
        visited[r][c]=true;
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !visited[nr][nc])
            {
                dfs(nr,nc,visited,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && !visited[0][j])
                dfs(0,j,visited,board);
            if(board[n-1][j]=='O' && !visited[n-1][j])
                dfs(n-1,j,visited,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
                dfs(i,0,visited,board);
            if(board[i][m-1]=='O' && !visited[i][m-1])
                dfs(i,m-1,visited,board);
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};