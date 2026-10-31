/*79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

//My soln
class Solution {
    bool dfs(int r,int c,string st,vector<vector<char>>& board,string& word,vector<vector<bool>>& visited)
    {
        if(st==word)
            return true;
        int n=board.size(),m=board[0].size();
        int len=st.length();
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==word[len] && !visited[nr][nc])
            {
                visited[nr][nc]=true;
                if(dfs(nr,nc,st+board[nr][nc],board,word,visited))
                    return true;
                visited[nr][nc]=false;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    string start=string(1,word[0]);
                    visited[i][j]=true;
                    if(dfs(i,j,start,board,word,visited))
                        return true;
                    visited[i][j]=false;
                }
            }
        }
        return false;
    }
};