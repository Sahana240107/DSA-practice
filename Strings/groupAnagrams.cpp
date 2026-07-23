/*49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs)
        {
            char freq[26]={0};
            for(char ch:s)
                freq[ch-'a']++;
            string key="";
            for(auto it:freq)
                key+="#"+to_string(it);
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};