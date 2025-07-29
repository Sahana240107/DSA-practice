/*Given a number represented as a string s (which may be very large), 
check whether it is divisible by 13 or not.*/
/*Input : s = "2911285"
Output : true
Explanation: 2911285 / 13 = 223945, which is a whole number with no remainder.*/
class Solution {
  public:
    bool divby13(string &s) {
        int digit,remainder=0;
        for(int i=0;i<s.length();i++)
        {
            digit=s[i]-'0';//convert to number
            remainder=(remainder*10+digit)%13;
        }
        return (remainder==0);
    }
};