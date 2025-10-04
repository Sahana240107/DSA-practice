/*Given a string `s` and an integer `k`, find the length of the **longest substring** that contains **at most k distinct characters**.

**Example 1:**
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece".

*/
int longDistinct(string s, int k) {
    int start = 0, maxCount = 0;
    unordered_map<char,int> freq;

    for(int end = 0; end < s.length(); end++) {
        freq[s[end]]++;

        // Shrink window if distinct characters > k
        while(freq.size() > k) {
            freq[s[start]]--;
            if(freq[s[start]] == 0) {
                freq.erase(s[start]);
            }
            start++;
        }

        // Update maximum length
        maxCount = max(maxCount, end - start + 1);
    }

    return maxCount;
}

