/*1614. Maximum Nesting Depth of the Parentheses
Easy
Topics
premium lock icon
Companies
Hint
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3*/

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                maxi=max(maxi,(int)st.size());
            }
            else if(s[i]==')')
                st.pop();
        }
        return maxi;
    }
};