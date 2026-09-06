/*383. Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(char c:ransomNote)
        {
            mp[c]++;
        }
        for(char c:magazine)
        {
            if(mp.find(c)!=mp.end())
            {
                mp[c]--;
                if(mp[c]==0)
                    mp.erase(c);
            }
        }
        return mp.empty();
    }
};