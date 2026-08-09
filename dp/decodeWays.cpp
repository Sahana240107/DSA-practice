/*91. Decode Ways
Medium
Topics
premium lock icon
Companies
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"

Output: 3

Explanation:

"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"

Output: 0

Explanation:

"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

*/

//top down
class Solution {
    int solve(int i,string& s,vector<int>& dp)
    {
        if(i==s.size())
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ways=solve(i+1,s,dp);
        if(i+1<s.size())
        {
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26)
                ways+=solve(i+2,s,dp);
        }
        return dp[i]=ways;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(0,s,dp);
    }
};

//bottom up
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]!='0')
            dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
                dp[i]+=dp[i-1];
            int num=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(num>=10 && num<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};

//space optimized
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int prev2=1;
        int prev1=0;
        if(s[0]!='0')
            prev1=1;
        for(int i=2;i<=n;i++)
        {
            int cur=0;
            if(s[i-1]!='0')
                cur+=prev1;
            int num=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(num>=10 && num<=26)
                cur+=prev2;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};