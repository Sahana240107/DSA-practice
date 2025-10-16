/*Given a matrix Grid[][] of size NxN. Calculate the absolute difference between the sums of its diagonals.

Example 1:

Input:
N=3
Grid=[[1,2,3],[4,5,6],[7,8,9]]
Output: 
0
Explanation:
Sum of primary diagonal = 1+5+9 = 15.
Sum of secondary diagonal = 3+5+7 = 15.
Difference = |15 - 15| = 0.*/
// User function template for C++

class Solution {
  public:
    int diagonalSumDifference(int N, vector<vector<int>> Grid) {
        int psum=0,ssum=0;
        for(int i=0;i<N;i++)
        {
            psum+=Grid[i][i];
            ssum=Grid[i][N-1-i];
        }
        return abs(psum-ssum);
        
    }
};