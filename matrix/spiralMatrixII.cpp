/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> ans(n,vector<int>(n));
         int count=1;
         int top=0,bottom=n-1;
         int left=0,right=n-1;
         while(top<=bottom && left<=right)
         {
            for(int j=left;j<=right;j++)
                ans[top][j]=count++;
            top++;
            for(int i=top;i<=bottom;i++)
                ans[i][right]=count++;
            right--;
            if(top<=bottom)
            {
                for(int j=right;j>=left;j--)
                    ans[bottom][j]=count++;
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                    ans[i][left]=count++;
                left++;
            }
         }
         return ans;
    }
};