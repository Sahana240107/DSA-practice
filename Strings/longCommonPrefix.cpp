/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int size=strs.size();
        for(int i=0;i<strs[0].length();i++)
        {
            char ch=strs[0][i];
            for(int j=1;j<size;j++)
            {
                if(i>=strs[j].length() || strs[j][i]!=ch)
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};