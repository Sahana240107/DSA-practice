/*Given a 2D binary matrix(1-based indexed) mat of dimensions nxm , determine the row that contains the minimum number of 1's.
Note: The matrix contains only 1's and 0's. Also, if two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.

Examples :

Input: mat = [[1, 1, 1, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 1, 1, 1]]
Output: 2
Explanation: Rows 2 and 3 contain the minimum number of 1's (2 each). Since, row 2 is less than row 3. Thus, the answer is 2.
*/
class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        // code here
        int sum=0,min1=INT_MAX,r=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<m;j++)
            {
                sum+=mat[i][j];
            }
            if(sum<min1)
                r=i;
            min1=min(min1,sum);
        }
        return r+1;
    }
};