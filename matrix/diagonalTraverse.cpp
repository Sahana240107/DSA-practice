/*Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dia(n+m-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dia[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<dia.size();i++)
        {
            if(i%2==0)
                reverse(dia[i].begin(),dia[i].end());
            for(int x:dia[i])
                ans.push_back(x);
        }
        return ans;
    }
};