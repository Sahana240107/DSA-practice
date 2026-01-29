/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(divisor==1)
            return dividend;
        bool neg=(dividend<0)^(divisor<0);
        long long div=llabs((long long)dividend);
        long long dis=llabs((long long)divisor);
        int quotient=0;
        while(div>=dis)
        {
            long long temp=dis,multiple=1;
            while((temp<<1)<=div)
            {
                temp<<=1;
                multiple<<=1;
            }
            div-=temp;
            quotient+=multiple;
        }
        return neg?-quotient:quotient;
    }
};