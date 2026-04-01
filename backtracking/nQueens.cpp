/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]*/
class Solution {
public:
    vector<vector<string>> result;
    bool isSafe(int r,int c,vector<int>& queens)
    {
        for(int preRow=0;preRow<r;preRow++)
        {
            int preCol=queens[preRow];
            if(c==preCol)
                return false;
            if(abs(preRow-r)==abs(preCol-c))
                return false;
        }
        return true;
    }
    void solve(int r,vector<int>& queens,int n)
    {
        if(r==n)
        {
            vector<string> board(n,string(n,'.'));
            for(int i=0;i<n;i++)
            {
                board[i][queens[i]]='Q';
            }
            result.push_back(board);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(isSafe(r,c,queens))
            {
                queens[r]=c;
                solve(r+1,queens,n);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> queens(n,-1);
        solve(0,queens,n);
        return result;
    }
};