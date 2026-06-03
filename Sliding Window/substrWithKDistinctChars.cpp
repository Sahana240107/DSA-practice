/*Substrings with K Distinct
Difficulty: MediumAccuracy: 20.46%Submissions: 197K+Points: 4Average Time: 20m
You are given a string s consisting of lowercase characters and an integer k, You have to count all possible substrings that have exactly k distinct characters.

Examples :

Input: s = "abc", k = 2
Output: 2
Explanation: Possible substrings are ["ab", "bc"]
Input: s = "aba", k = 2
Output: 3
Explanation: Possible substrings are ["ab", "ba", "aba"]
Input: s = "aa", k = 1
Output: 3
Explanation: Possible substrings are ["a", "a", "aa"]*/
class Solution {
  public:
    int atmostKDistinct(string &s,int k)
    {
        if(k<=0)
            return 0;
        vector<int> mp(26,0);
        int left=0,distinct=0;
        long long count=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']==1)
                distinct++;
            while(distinct>k)
            {
                mp[s[left]-'a']--;
                if(mp[s[left]-'a']==0)
                    distinct--;
                left++;
            }
            int len=i-left+1;
            count+=len;
        }
        return count;
    }
    int countSubstr(string& s, int k) {
        // code here
        return atmostKDistinct(s,k)-atmostKDistinct(s,k-1);
    }
};