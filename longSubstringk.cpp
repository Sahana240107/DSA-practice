/*You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the **length** of the **longest substring** that contains exactly **k** distinct characters.

**Note :** If no such substring exists, return **-1**.

**Examples:**

Input:s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
```*/
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int maxlength=-1,start=0;
        unordered_map<char,int> freq;
        for(int end=0;end<s.length();end++)
        {
            freq[s[end]]++;
            if(freq.size()==k)
                maxlength=max(maxlength,end-start+1);
            while(freq.size()>k)
            {
                freq[s[start]]--;
                if(freq[s[start]]==0)
                    freq.erase(s[start]);
                start++;
            }
        }
        return maxlength;
    }
};