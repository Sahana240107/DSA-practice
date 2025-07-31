/*Given a string s. The task is to find the first repeated character in it. 
We need to find the character that occurs more than once and whose index of second occurrence is smallest. 
s contains only lowercase letters.
Examples :
Input: s ="geeksforgeeks"
Output: "e"
Explanation: 'e' repeats at third position.*/
class Solution {
  public:
    string firstRepChar(string s) {
        int count[26]={0};
        if(s.length()<2)
        {
            return "-1";
        }
        for(int i=0;i<s.length();i++)
        {
            if(count[s[i]-97]>0)
            {
                return string(1,s[i]);//convert to string
            }
            else
            {
                count[s[i]-97]++;
            }
        }
        return "-1";
    }
};