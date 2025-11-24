/*Given two strings txt and pat having lowercase letters, the task is to check if any permutation of pat is a substring of txt.

Examples:

Input: txt = "geeks", pat = "eke"
Output: true
Explanation: "eek" is a permutation of "eke" which exists in "geeks".
Input: txt = "programming", pat = "rain"
Output: false
Explanation: No permutation of "rain" exists as a substring in "programming".
*/
// User function Template for C++
class Solution {
  public:
    bool search(string& txt, string& pat) {
        // Write your code here
        int n=txt.size(),m=pat.size();
        vector<int> fpat(26,0),ftxt(26,0);
        for(char c:pat)
        {
            fpat[c-'a']++;
        }
        for(int i=0;i<m;i++)
        {
            char c=txt[i];
            ftxt[c-'a']++;
        }
        if(fpat==ftxt)
            return true;
        for(int i=m;i<n;i++)
        {
            ftxt[txt[i]-'a']++;
            ftxt[txt[i-m]-'a']--;
            if(ftxt==fpat)
                return true;
        }
        return false;
    }
};