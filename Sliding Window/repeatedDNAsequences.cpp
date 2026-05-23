/*The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int k=10;
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i=0;i+k<=s.size();i++)
        {
            string str=s.substr(i,k);
            if(mp[str]==1)
            {
                ans.push_back(str);
            }
            mp[str]++;
        }
        return ans;
    }
};
