/*Given a number n, check if the number is perfect or not. A number is said to be perfect if sum of all its factors excluding the number itself is equal to the number.

Examples:

Input: n = 6
Output: true 
Explanation: Factors of 6 are 1, 2, 3 and 6. Excluding 6 their sum is 6 which is equal to n itself. So, it's a Perfect Number.*/
class Solution {
  public:
    bool isPerfect(int n) {
        // code here
        int sum=1;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum+=i;
                if(i!=n/i)
                    sum+=n/i;
            }
        }
        return sum==n;
    }
};