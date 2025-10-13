/*Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
*/
//Using frequency map
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freq;
    int start = 0, maxLen = 0;

    for (int end = 0; end < s.length(); end++) {
        freq[s[end]]++;

        while (freq[s[end]] > 1) {
            freq[s[start]]--;
            if (freq[s[start]] == 0) freq.erase(s[start]);
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}



