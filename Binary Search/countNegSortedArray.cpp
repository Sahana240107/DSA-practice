/*# **1351. Count Negative Numbers in a Sorted Matrix**

Given a `m x n` matrix `grid` which is sorted in non-increasing order both row-wise and column-wise, return *the number of **negative** numbers in* `grid`.

**Example 1:**

```
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```

**Example 2:**

```
Input: grid = [[3,2],[1,0]]
Output: 0
```*/
//Binary Search to find Fist negative in each row
class Solution {//Binary Search to find First Negative
public:
    int countNegatives(vector<vector<int>>& grid) {
        int neg=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            int low=0,high=n-1,firstNeg=-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(grid[i][mid]<0)
                {
                    firstNeg=mid;
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            if(firstNeg!=-1)
                neg+=(n-firstNeg);
        }
        return neg;
    }
};

//optimal O(m+n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int neg=0;
        int m=grid.size(),n=grid[0].size();
        int row=m-1,col=0;
        while(row>=0 && col<n)
        {
            if(grid[row][col]<0)
            {
                neg+=(n-col);
                row--;
            }
            else
                col++;
        }
        return neg;
    }
};