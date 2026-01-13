/*Check whether the given number is power of 4*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        return (n&(n-1))==0 && (n&0x55555555);
    }
};