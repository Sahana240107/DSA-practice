//Given an integer x, return true if x is a palindrome, and false otherwise.
class Solution {
public:
    bool isPalindrome(int x) {
        long int rev=0,a,t=x;
        while(x>0)
        {
            a=x%10;
            x/=10;
            rev=rev*10+a;
        }
        if(t==rev)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};