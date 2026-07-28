/*5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"*/
class Solution {
    int start=0,maxlen=0;
    void expand(string& s,int l,int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }
        int len=r-l-1;
        if(len>maxlen)
        {
            maxlen=len;
            start=l+1;
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return s.substr(start,maxlen);
    }
};