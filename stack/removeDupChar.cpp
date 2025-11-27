/*You are given string s. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together. 

Examples:

Input: s = "aaabbaaccd"
Output: ad
Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad
*/
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char> st;
        for(char c:s)
        {
            if(!st.empty() && st.top()==c)
                st.pop();
            else
                st.push(c);
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};