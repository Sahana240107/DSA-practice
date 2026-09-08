/*500. Keyboard Row
Solved
Easy
Topics
premium lock icon
Companies
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]

Output: ["Alaska","Dad"]

Explanation:

Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

Example 2:

Input: words = ["omk"]

Output: []

Example 3:

Input: words = ["adsdf","sfd"]

Output: ["adsdf","sfd"]*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string firstrow="qwertyuiop",secondrow="asdfghjkl",thirdrow="zxcvbnm";
        vector<string> ans;
        vector<int> rows(26,0);
        for(char c:firstrow)
        {
            rows[c-'a']=1;
        }
        for(char c:secondrow)
        {
            rows[c-'a']=2;
        }
        for(char c:thirdrow)
        {
            rows[c-'a']=3;
        }
        for(string str:words)
        {
            string s=str;
            for(char &c:s)
                c=tolower(c);
            int row=rows[s[0]-'a'];
            bool onerow=true;
            for(char c:s)
            {
                if(rows[c-'a']!=row)
                {
                    onerow=false;
                    break;
                }
            }
            if(onerow)
                ans.push_back(str);
        }
        return ans;
    }
};