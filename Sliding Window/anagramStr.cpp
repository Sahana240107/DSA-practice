/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size(),m=p.size();
        if(m>n)
            return ans;
        vector<int> fs(26,0),fp(26,0);
        for(char c:p)
        {
            fp[c-'a']++;
        }
        for(int i=0;i<m;i++)
        {
            fs[s[i]-'a']++;
        }
        if(fp==fs)
            ans.push_back(0);
        for(int i=m;i<s.size();i++)
        {
            fs[s[i]-'a']++;
            fs[s[i-m]-'a']--;
            if(fs==fp)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};