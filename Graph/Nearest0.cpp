/*542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dist(n,vector<int> (m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            int d=dist[r][c];
            q.pop();
            int dr[]={0,0,-1,1};
            int dc[]={-1,1,0,0};
            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]==-1)
                {
                    dist[nr][nc]=d+1;
                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
};
