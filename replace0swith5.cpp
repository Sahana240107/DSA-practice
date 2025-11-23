/*You are given an integer n. You need to convert all zeroes of n to 5.
Examples:
Input: n = 1004
Output: 1554
Explanation: There are two zeroes in 1004 on replacing all zeroes with 5,the new number will be 1554.*/
class Solution {
  public:
    int convertFive(int n) {
        int a,res=0,i=1;
        if(n==0)
        {
            return 5;
        }
        while(n!=0)
        {
            a=n%10;
            n/=10;
            if(a==0)
            {
                res=res+5*i;
            }
            else{
                res=res+a*i;
            }
            i*=10;
        }
        return res;
    }
};