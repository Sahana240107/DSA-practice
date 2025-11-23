/*Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        while (top <= bottom && left <= right) {
            //  Traverse from Left to Right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++; // move the top boundary down

            // Traverse from Top to Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // move the right boundary left

            //  Traverse from Right to Left (only if top <= bottom)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--; // move the bottom boundary up
            }

            // Traverse from Bottom to Top (only if left <= right)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // move the left boundary right
            }
        }

        return ans;
    }
};

