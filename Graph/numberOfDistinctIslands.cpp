/*Number of Distinct Islands
Difficulty: MediumAccuracy: 62.29%Submissions: 134K+Points: 4Average Time: 20m
Given a grid of size n × m, consisting of characters 'L' and 'W', where 'L' represents Land and 'W' represents Water, find the number of distinct islands in the grid.

An island is a group of one or more connected land cells. Two land cells are considered connected if they are adjacent horizontally or vertically (4-directional connectivity).

Two islands are considered distinct if their shapes are different.
If two shapes become same after rotation, then they are considered different.  In the second example below, the two corner L shaps are considered different.
Examples :

Input: n = 4, m = 5
 
Output: 1
Explanation: The grid contains two islands. Both islands have the same shape (a 2 × 2 block of land), so they are counted as a single distinct island.

Input: n = 4, m = 5
 
Output: 3
Explanation: There are four islands in the grid. Two islands have the same shape, while the other two have different shapes. Therefore, the number of distinct island shapes is 3.

*/
class Solution {
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& visited,
    vector<pair<int,int>>& vec,int sr,int sc)
    {
        visited[r][c]=true;
        vec.push_back({r-sr,c-sc});
        int n=grid.size(),m=grid[0].size();
        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='L' && !visited[nr][nc])
                dfs(nr,nc,grid,visited,vec,sr,sc);
        }
    }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='L' && !visited[i][j])
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,visited,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
