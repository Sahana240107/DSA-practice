/*Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[0, 1, 2], 
                [3, 4, 5], 
                [6, 7, 8]] 
Output: [[2, 5, 8],
        [1, 4, 7],
        [0, 3, 6]]*/

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        long n=mat.size();
        for(int i=0;i<n;i++)//transpose in place
        {
            for(int j=i;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }
        for(int i=0;i<n;i++)//reverse columns
        {
            int j=0,k=n-1;
            while(j<k)
            {
                swap(mat[j][i],mat[k][i]);
                j++;
                k--;
            }
        }
    }
};
