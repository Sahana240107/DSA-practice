/*You are given a square matrix of size n x n. Your task is to find the transpose of the given matrix.
The transpose of a matrix is obtained by converting all the rows to columns and all the columns to rows.*/
class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int row=mat.size();
        int col;
        if(row>0)
        {
            col=mat[0].size();
        }
        vector<vector<int>> res(col,vector<int>(row));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                res[j][i]=mat[i][j];
            }
        }
        return res;
    }
};