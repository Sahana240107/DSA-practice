/*Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

Examples:

Input: s = "testsample"
Output: 'e'
Explanation: 'e' is the character which is having the highest frequency.
Input: s = "output"
Output: 't'
Explanation: 't' and 'u' are the characters with the same frequency, but 't' is lexicographically smaller.
*/
class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        int freq[26] = {0};

        for(char c : s)
            freq[c - 'a']++;

        int maxfreq = 0;
        char ans = 'a';

        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxfreq) {
                maxfreq = freq[i];
                ans = char(i + 'a');
            }
        }

        return ans;
    }
};
