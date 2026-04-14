/*Given a string, your task is to reverse the string keeping the spaces intact to their positions.

Example 1:

Input:
S = "Help others"
Output: sreh topleH
Explanation: The space is intact at index 4
while all other characters are reversed.
*/

class Solution {
  public:

    string reverseWithSpacesIntact(string s) {
        // code here.
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=' ' && s[j]!=' ')
                swap(s[i],s[j]);
            if(s[i]==' ')
                i++;
            else if(s[j]==' ')
                j--;
            else
            {
                i++;
                j--;
            }
        }
        return s;
    }
};