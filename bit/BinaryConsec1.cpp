/*Given a number n. Find the length of the longest consecutive 1s in its binary representation.

Examples:

Input: n = 14
Output: 3
Explanation: Binary representation of 14 is 1110, in which 111 is the longest consecutive set bits of length is 3.
*/
class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        int count=0,maxCount=0;
        while(n)
        {
            if(n&1)
            {
                count++;
                maxCount=max(maxCount,count);
            }
            else
                count=0;
            n>>=1;
        }
        return maxCount;
    }
};


//Brian Kernighan Method
int maxConsecutiveOnes(int n) {
    int count = 0;
    while (n) {
        n = n & (n << 1);
        count++;
    }
    return count;
}
