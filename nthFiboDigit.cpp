/*Given a positive integer N, 
find the last digit of the Nth term from the Fibonacci series.
Input:
N = 14
Output:
7
Explanation:
14th Fibonacci number is 377
It's last digit is 7*/
class Solution {
  public:
    int fib(int N) {

        long first=0,second=1,next;
        if(N<=1)
        {
            return N;
        }
        for(int i=2;i<=N;i++)
        {
            next=(first+second)%10;//we just need the last digit
            first=second;
            second=next;
        }
        return (second%10);
    }
};