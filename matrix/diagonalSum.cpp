/*Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the
 elements on the secondary diagonal that are not part of the primary diagonal.*/
 class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i];//primary diagonal
            sum+=mat[i][n-1-i];//secondary diagonal
        }
        if(n%2!=0)
        {
            sum-=mat[n/2][n/2];//remove center counted twice
        }
        return sum;
    }
};