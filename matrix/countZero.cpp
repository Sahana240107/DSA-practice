/*Given a N X N binary Square Matrix where each row and column of the matrix is sorted in ascending order. Find the total number of zeros present in the matrix.

Example 1:

Input:
N = 3
A = {{0, 0, 0},
     {0, 0, 1},
     {0, 1, 1}}
Output: 6
Explanation: 
The first, second and third row contains 3, 2 and 1
zeroes respectively.*/
//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>> A) {
        // code here
        int count=0;
        int n=A.size();
        int m=A[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i][j]==0)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};