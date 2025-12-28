/*Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1,j=b.length()-1,carry=0;
        string res;
        while(i>=0 || j>=0 || carry==1)
        {
            int sum=carry;
            if(i>=0)
                sum+=a[i]-'0';
            if(j>=0)
                sum+=b[j]-'0';
            res+=(sum%2)+'0';
            carry=sum/2;
            i--;j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//leading zeros version

// User function template for C++
class Solution {
    string leadingZero(string s)
    {
        int lead=0;
        for(char x:s)
        {
            if(x=='0')
                lead++;
            else
                break;
        }
        if(lead==s.length())
            return "0";
        return s.substr(lead);
        
    }
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        s1=leadingZero(s1);
        s2=leadingZero(s2);
        int i=s1.length()-1,j=s2.length()-1,carry=0;
        string res;
        while(i>=0||j>=0||carry==1)
        {
            int sum=carry;
            if(i>=0)
                sum+=s1[i]-'0';
            if(j>=0)
                sum+=s2[j]-'0';
            res+=(sum%2)+'0';
            carry=sum/2;
            i--;j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};