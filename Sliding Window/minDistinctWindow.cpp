/*Smallest distinct window
Difficulty: MediumAccuracy: 31.85%Submissions: 125K+Points: 4
Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 7
Explanation: There are multiple substring with smallest length that contains all characters of str, "eksforg" and "ksforge".*/

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_map<char,int> mp;
        for(char c:str)
        {
            mp[c]=1;
        }
        int n=mp.size();
        int left=0,start=0,min_len=INT_MAX;
        for(int i=0;i<str.size();i++)
        {
            if(mp.find(str[i])!=mp.end())
            {
                mp[str[i]]--;
                if(mp[str[i]]>=0)
                    n--;
            }
            while(n==0)
            {
                int len=i-left+1;
                if(min_len>len)
                {
                    min_len=len;
                    start=left;
                }
                if(mp.find(str[left])!=mp.end())
                {
                    mp[str[left]]++;
                    if(mp[str[left]]>0)
                        n++;
            
                }
                left++;
            }
        }
        return min_len==INT_MAX?0:min_len;
    }
};