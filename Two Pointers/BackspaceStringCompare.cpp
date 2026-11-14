/*844. Backspace String Compare

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 
Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 
Follow up: Can you solve it in O(n) time and O(1) space?*/

//Stack
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size(),m=t.size();
        stack<char> st1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
                st1.push(s[i]);
            else if(!st1.empty())
                st1.pop();
        }
        stack<char> st2;
        for(int i=0;i<m;i++)
        {
            if(t[i]!='#')
                st2.push(t[i]);
            else if(!st2.empty())
                st2.pop();
        }
        return st1==st2;
    }
};

//Two Pointers
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1,j=t.size()-1;
        while(i>=0 || j>=0)
        {
            int skip1=0,skip2=0;
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    skip1++;
                    i--;
                }
                else if(skip1>0)
                {
                    skip1--;
                    i--;
                }
                else
                    break;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    skip2++;
                    j--;
                }
                else if(skip2>0)
                {
                    skip2--;
                    j--;
                }
                else
                    break;
            }
            if((i>=0) && (j>=0) && s[i]!=t[j])
                return false;
            if((i>=0)!=(j>=0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};

