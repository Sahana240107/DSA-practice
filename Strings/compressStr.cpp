/*You are given the string S . Compress the string when lower and upper cases are the same. In compressed string characters should be in lowercase.

Example 1:

Input: S = "aaABBb"
Output: "3a3b"
Explanation: As 'a' appears 3 times
consecutively and 'b' also 3 times,
and 'b' and 'B' considered as same. 
*/
string transform(string S) {
    // complete the function here
    string ans;
    int n=S.length();
    for(int i=0;i<S.length();i++)
    {
        char c=tolower(S[i]);
        int count=1;
        while(i+1<n && c==tolower(S[i+1]))
        {
            count++;
            i++;
        }
        ans+=to_string(count);
        ans+=c;
    }
    return ans;
}
