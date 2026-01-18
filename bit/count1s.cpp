/*Given a positive integer n. Your task is to return the count of set bits.

Examples:

Input: n = 6
Output: 2
Explanation: Binary representation is '110', so the count of the set bit is 2.*/
class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n)
        {
            if(n&1)
                count++;
            n>>=1;
        }
        return count;
    }
};

//Brian Kernighan Method

class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n)
        {
            n=n&(n-1);
            count++;
        }
        return count;
    }
};