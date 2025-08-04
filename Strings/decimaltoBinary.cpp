/*Given a decimal number n, return its binary equivalent.
*/
class Solution {
  public:
    string decToBinary(int n) {
       string s="";
       while(n>0)
       {
           s=char(n%2+'0')+s;
           n/=2;
       }
       return s;
        
    }
};