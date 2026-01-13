/*Given a non-negative integer n. You have to check if it is a power of 2 or not. 

Examples

Input: n = 8
Output: true
Explanation: 8 is equal to 2 raised to 3 (23 = 8).
Input: n = 98
Output: false
Explanation: 98 cannot be obtained by any power of 2.
*/
class Solution {
  public:
    bool isPowerofTwo(int n) {
        if(n<=0)
            return false;
        return (n&(n-1))==0;
    }
};