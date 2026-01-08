/*Given a string s, reverse the string without reversing its individual words. Words are separated by dots(.).

Note: The string may contain leading or trailing dots(.) or multiple dots(.) between two words. The returned string should only have a single dot(.) separating the words, and no extra dots should be included.

Examples :

Input: s = "i.like.this.program.very.much"
Output: "much.very.program.this.like.i"
Explanation: The words in the input string are reversed while maintaining the dots as separators, resulting in "much.very.program.this.like.i".
Input: s = "..geeks..for.geeks."
Output: "geeks.for.geeks"
Explanation: After removing extra dots and reversing the whole string, the input string becomes "geeks.for.geeks".
Input: s = "..home....."
Output: "home"
Explanation: The input string contains only one word with extra dots around it. After removing the extra dots, the output is "home".*/
class Solution {
public:
    string reverseWords(string &s) {
        string ans = "";
        int i = s.size() - 1;

        while (i >= 0) {
            // Skip dots
            while (i >= 0 && s[i] == '.')
                i--;

            if (i < 0) break;

            // Extract word
            int j = i;
            while (j >= 0 && s[j] != '.')
                j--;

            // Append word
            if (!ans.empty())
                ans += '.';
            ans += s.substr(j + 1, i - j);

            i = j - 1;
        }
        return ans;
    }
};
