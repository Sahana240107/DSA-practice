/*85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1*/

class Solution {
    int longestRect(vector<int>& height)
    {
        int maxi=0;
        int n=height.size();
        stack<int> st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n||height[st.top()]>=height[i]))
            {
                int h=height[st.top()];
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int width=nse-pse-1;
                maxi=max(maxi,width*h);
            }
            st.push(i);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> height(m);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    height[j]++;
                else
                    height[j]=0;
            }
            maxi=max(maxi,longestRect(height));
        }
        return maxi;
    }
};