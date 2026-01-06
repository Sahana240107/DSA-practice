/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
 
Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
*/
//easier approach
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0,i=s.length()-1;
        while(i>=0 && s[i]==' ')
            i--;
        while(i>=0 && s[i]!=' ')
        {
            len++;
            i--;
        }
        return len;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        int last=0;
        for(char c:s)
        {
            if(c==' ')
            {
                if(word.length()!=0)
                    last=word.length();
                word="";
            }
            else
                word+=c;
        }
        return (word.length()==0)?last:word.length();
    }
};