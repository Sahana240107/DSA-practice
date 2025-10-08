/*You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

Examples:

Input: image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2

Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]

Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].*/
class Solution {
    void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& ans,int newColor,int iniColor)
    {
        int n=image.size();
        int m=image[0].size();
        ans[sr][sc]=newColor;
        int delr[]={-1,1,0,0};
        int delc[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int nr=sr+delr[i];
            int nc=sc+delc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]!=newColor && image[nr][nc]==iniColor)
            {
                ans[nr][nc]=newColor;
                dfs(nr,nc,image,ans,newColor,iniColor);
            }
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        ans[sr][sc]=newColor;
        dfs(sr,sc,image,ans,newColor,iniColor);
        return ans;
        
        
    }
};