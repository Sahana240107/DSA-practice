/*Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

 

Example 1:


Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
Example 2:


Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
Example 3:


Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
 */
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3,vector<int> (3,-1));
        for(int i=0;i<moves.size();i++)
        {
            int r=moves[i][0];
            int c=moves[i][1];
            (i%2==0)?grid[r][c]=1:grid[r][c]=0;
        }
        for(int i=0;i<3;i++)
        {
            if(grid[i][0]==-1)
            {
                continue;
            }
            else if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2])
            {
                return (grid[i][0]==1)?"A":"B";
            }
        }
        for(int j=0;j<3;j++)
        {
            if(grid[0][j]==-1)
                continue;
            else if(grid[0][j]==grid[1][j] && grid[1][j]==grid[2][j])
            {
                return (grid[0][j]==1)?"A":"B";
            }
        }
        if(grid[1][1]!=-1)
        {
            if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
            {
               return (grid[0][0]==1)?"A":"B";
            }
            else if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
            {
                return (grid[0][2]==1)?"A":"B";
            }
        }
        return moves.size()==9?"Draw":"Pending";
    }
};
/*
A Tic-Tac-Toe board of size 3X3 is given after all the moves are played, i.e., all nine spots are filled. Find out if the given board is valid, i.e., is it possible to reach this board position after a set of moves or not.
Note that every arbitrarily filled grid of 9 spaces isn’t valid, e.g., a grid filled with 3 X and 6 O isn’t a valid situation because each player needs to take alternate turns.

Note:  The game starts with X



Examples:

Input:
board[] = {'X', 'X', 'O', 
           'O', 'O', 'X',
           'X', 'O', 'X'};
Output: Valid
Explanation: This is a valid board.
Input:
board[] = {'O', 'X', 'X', 
           'O', 'X', 'X',
           'O', 'O', 'X'};
Output: Invalid
Explanation: Both X and O cannot win.
*/

// User function template for C++

class Solution {
    int win(char b[9]) {
        int count=0;
        int lines[8][3] = {
            {0,1,2},{3,4,5},{6,7,8}, // rows
            {0,3,6},{1,4,7},{2,5,8}, // columns
            {0,4,8},{2,4,6}          // diagonals
        };

        for (int i = 0; i < 8; i++) {
            if (b[lines[i][0]] ==b[lines[i][1]]  && b[lines[i][1]]==b[lines[i][2]])
                count++;
        }
        return count;
    }
  public:
    bool isValid(char board[9]) {
        int x=0,o=0;
        for(int i=0;i<9;i++)
        {
            char c=board[i];
            if(c=='O')
                o++;
            else 
                x++;
        }
        if(x!=5 || o!=4)
            return false;
        int count=win(board);
        if(count>1)
            return false;
        return true;
    }
};