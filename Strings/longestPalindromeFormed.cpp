/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        int count=0;
        for(char c:s)
        {
            freq[c]++;
            if(freq[c]%2==0)
                count+=2;
        }
        for(auto it:freq)
        {
            if(it.second%2!=0)
            {
                count+=1;
                break;
            }
        }
        return count;
    }
};