/*Given two strings text and pattern, find the first index where pattern exactly matches with any substring of text. 
Return -1 if pattern doesn't exist as a substring in text.
Example 1:
Input:
text = gffgfg
pattern = gfg
Output: 3
Explanation:  Considering 0-based indexing, substring of text from 3rd to last index is gfg.*/
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        long n=text.size(),m=pat.size();
        int j;
        for(int i=0;i<=n-m;i++)
        {
            j=0;
            while(j<m && text[i+j]==pat[j])
            {
                j++;
            }
            if(j==m)
            {
                return i;
            }
        }
        return -1;
    }
};