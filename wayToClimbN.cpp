/*There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time.
 Your task is to count the number of ways, the person can reach the top (order does matter).*/
 class Solution {
  public:
    int countWays(int n) {// fibonacci pattern
       int first=1,second=1,next;
        if(n<=1)
        return 1;
        for(int i=2;i<=n;i++)
        {
            next=first+second;
            first=second;
            second=next;
        }
        return second;
    }
};
