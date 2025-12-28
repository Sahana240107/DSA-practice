/*You are given a binary string s of length n. You have to perform binary addition of the string with '1'.

Example 1:

Input: 
n = 4
s = 1010
Output: 1011
Explaination: 
The decimal equivalent of given s is 10, 
Adding 1 gives 11, its binary representation
is 1011.
*/
class Solution {
  public:
    string binaryAdd(int n, string s) {
        // code here
        int i=n-1,carry=1;
        string res;
        while(i>=0 || carry==1)
        {
            int sum=carry;
            if(i>=0)
                sum+=s[i]-'0';
            res+=(sum%2)+'0';
            carry=sum/2;
            i--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};