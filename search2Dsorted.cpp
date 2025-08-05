/*Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order 
and a number x,the task is to find whether element x is present in the matrix.
Examples:
Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
Output: false
Explanation: 62 is not present in the matrix, so output is false.*/
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        long row=mat.size();
        long col=mat[0].size();
        for(int i=0;i<row;i++)
        {
            if(mat[i][col-1]>=x)//since sorted find the row first
            {
                for(int j=col-1;j>=0;j--)
                {
                    if(mat[i][j]==x)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};