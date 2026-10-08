/*916. Word Subsets

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.
Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]

Output: ["facebook","google","leetcode"]

Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]

Output: ["leetcode"]

Example 3:

Input: words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]

Output: ["cccbb"]*/

//Brute force
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>> mp(words2.size(),vector<int> (26,0));
        for(int i=0;i<words2.size();i++)
        {
            for(char c:words2[i])
            {
                mp[i][c-'a']++;
            }
        }
        vector<string> universal;
        for(string st:words1)
        {
            vector<int> freq(26,0);
            for(char c:st)
            {
                freq[c-'a']++;
            }
            bool flag=true;
            for(int i=0;i<words2.size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(freq[j]<mp[i][j])
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
                universal.push_back(st);
        }
        return universal;
    }
};

//Optimized
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req(26,0);
        for(int i=0;i<words2.size();i++)
        {
            vector<int> freq(26,0);
            for(char c:words2[i])
            {
                freq[c-'a']++;
                if(freq[c-'a']>req[c-'a'])
                    req[c-'a']=freq[c-'a'];
            }
        }
        vector<string> universal;
        for(string st:words1)
        {
            vector<int> freq(26,0);
            for(char c:st)
            {
                freq[c-'a']++;
            }
            bool flag=true;
            for(int j=0;j<26;j++)
            {
                if(freq[j]<req[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                universal.push_back(st);
        }
        return universal;
    }
};