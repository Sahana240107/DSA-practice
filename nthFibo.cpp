/*Given a non-negative integer n, your task is to find the nth Fibonacci number.*/
class Solution {
  public:
    int nthFibonacci(int n) {
        if(n<=1)
        {
            return n;
        }
        int first=0,second=1,next;
        for(int i=2;i<=n;i++)
        {
            next=first+second;
            first=second;
            second=next;
        }
        return second;
    }
};