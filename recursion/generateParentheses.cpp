/*22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]*/

class Solution {
    void helper(int open,int close,string cur,int& n,vector<string>& ans)
    {
        if(open==n && close==n)
        {
            ans.push_back(cur);
            return;
        }
        if(open<n)
            helper(open+1,close,cur+'(',n,ans);
        if(close<open)
            helper(open,close+1,cur+')',n,ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        helper(open,close,"",n,ans);
        return ans;
    }
};