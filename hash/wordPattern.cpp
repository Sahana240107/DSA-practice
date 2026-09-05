/*290. Word Pattern
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false*/

//My first thought with map and set
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> mp(26,"");
        unordered_set<string> words;
        int wordstart=0;
        for(char c:pattern)
        {
            if(wordstart>=s.size())
                return false;
            string w="";
            while(wordstart<s.size() && s[wordstart]!=' ')
            {
                w+=s[wordstart];
                wordstart++;
            }
            if(mp[c-'a']!="" && mp[c-'a']!=w)
                return false;
            else if(mp[c-'a']=="")
            {
                if(words.find(w)!=words.end())
                    return false;
                mp[c-'a']=w;
                words.insert(w);
            }
            if(wordstart<s.size())
                wordstart++;
        }
        if(wordstart<s.size())
            return false;
        return true;
    }
};

//Two maps
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        int start=0;
        for(char c:pattern)
        {
            string word="";
            if(start>=s.size())
                return false;
            while(start<s.size() && s[start]!=' ')
            {
                word+=s[start];
                start++;
            }
            if(start<s.size())
                start++;
            if(mp1.find(c)!=mp1.end())
            {
                if(mp1[c]!=word)
                    return false;
            }
            else
            {
                if(mp2.find(word)!=mp2.end())
                    return false;
                mp1[c]=word;
                mp2[word]=c;
            }
        }
        if(start<s.size())
            return false;
        return true;
    }
};