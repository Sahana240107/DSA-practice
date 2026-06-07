/*# **Nth Root of a Number using Binary Search**

**Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.Examples

`Input: N = 3, M = 27Output: 3Explanation: The cube root of 27 is equal to 3.
Input : N = 4, M = 69Output: -1Explanation : The 4th root of 69 does not exist. So, the answer is -1.`***/

class Solution {
public:
    // Function to find N-th root of M using binary search
    int nthRoot(int n, int m) {
       int low=1,high=m;
       while(low<=high)
       {
        int mid=low+(high-low)/2;
        long long ans=1;
        for(int i=0;i<n;i++)
        {
            ans*=mid;
            if(ans>m)
                break;
        }
        if(ans==m)
            return mid;
        else if(ans<m)
            low=mid+1;
        else   
            high=mid-1;
       }
       return -1;
    }
};