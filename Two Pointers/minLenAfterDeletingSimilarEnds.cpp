/*1750. Minimum Length of String After Deleting Similar Ends
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).

 

Example 1:

Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.
Example 2:

Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".
Example 3:

Input: s = "aabccabba"
Output: 3
Explanation: An optimal sequence of operations is:
- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".*/

class Solution {
public:
    int minimumLength(string s) {
        int left=0,right=s.size()-1,n=s.size();
        while(left<=right)
        {
            if(left!=right && s[left]==s[right])
            {
                left++;
                right--;
            }
            else if(left>0 && s[left-1]==s[left])
                left++;
            else if(right<n-1 && s[right+1]==s[right])
                right--;
            else
                break;
        }
        if(left>right)
            return 0;
        return right-left+1;
    }
};

//Perfect Two Pointer Approach
class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left<right && s[left]==s[right])
        {
            char c=s[left];
            while(left<=right && s[left]==c)
                left++;
            while(left<=right && s[right]==c)
                right--;
        }
        return right-left+1;
    }
};