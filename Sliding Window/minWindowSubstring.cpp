/*76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/
class Solution {
public:
    string minWindow(string s, string t) {
       
        int n=s.size(),m=t.size();
        if(m>n)
            return "";
        unordered_map<char,int> mp;
        for(char c:t)
            mp[c]++;
        int left=0,min_len=INT_MAX,start=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]]--;
                if(mp[s[i]]>=0)
                    m--;
            }
            while(m==0)
            {
                int len=i-left+1;
                if(len<min_len)
                {
                    min_len=len;
                    start=left;
                }
                if(mp.find(s[left])!=mp.end())
                {
                    mp[s[left]]++;
                    if(mp[s[left]]>0)
                        m++;
                }
                left++;
            }
        }
        return min_len==INT_MAX?"":s.substr(start,min_len);
    }
};