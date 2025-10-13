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


//Using index map (last occurrence)
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int start = 0, maxLen = 0;

    for (int end = 0; end < s.length(); end++) {
        char c = s[end];

        // if char seen before and inside current window
        if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= start) {
            start = lastIndex[c] + 1;
        }

        lastIndex[c] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

//Using ASCII
int lengthOfLongestSubstring(string s) {
    vector<int> last(256, -1); // store last seen index of each char
    int start = 0, maxLen = 0;

    for (int end = 0; end < s.length(); end++) {
        if (last[s[end]] >= start) {
            start = last[s[end]] + 1;
        }
        last[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}
