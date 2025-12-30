/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.*/

//naive approach
class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        for(char c:s)
        {
            if(isalnum(c))
                clean+=tolower(c);
        }
        string rev=clean;
        reverse(rev.begin(),rev.end());
        return clean==rev;
    }
};