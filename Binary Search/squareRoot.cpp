/*Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number.

Examples:

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.*/
class Solution {
  public:
    int floorSqrt(int n) {
        long long left=1,right=n,mid,sq,ans;
        if(n==0 || n==1)
        {
            return n;
        }
        while(left<=right)
        {
            mid=left+(right-left)/2;
            sq=1LL*mid*mid;
            if(sq==n)
            {
                return mid;
            }
            else if(sq<n)
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};