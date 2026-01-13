/*Given a non-negative integer n. You have to check if it is a power of 3 or not.*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        int maxPow=pow(3,19);
        return maxPow%n==0;
    }
};