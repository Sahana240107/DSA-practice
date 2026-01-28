/*Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,maxi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')   
                left++;
            else
                right++;
            if(left==right)
                maxi=max(maxi,right*2);
            else if(right>left)
            {
                left=0;
                right=0;
            }
        }
        left=0,right=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left==right)
                maxi=max(maxi,left*2);
            else if(left>right)
            {
                left=0;
                right=0;
            }
        }
        return maxi;
    }
};