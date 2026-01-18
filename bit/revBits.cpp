/*Reverse bits of a given 32 bits signed integer.

 

Example 1:

Input: n = 43261596

Output: 964176192

Explanation:

Integer	Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000
*/
class Solution {
public:
    int reverseBits(int n) {
      int ans=0;
      for(int i=0;i<32;i++)
      {
        ans=(ans<<1)|(n&1);
        n>>=1;
      }
      return ans;
    }
};

/*Given a non-negative integer n. Reverse the bits of n and print the number obtained after reversing the bits.
Note:  The actual binary representation of the number is being considered for reversing the bits, no leading 0’s are being considered.
 
Example 1:
Input : 
N = 11
Output:
13
Explanation:
(11)10 = (1011)2.
After reversing the bits we get:
(1101)2 = (13)10.
*/

// User function Template for C++

class Solution {
  public:
    unsigned int reverseBits(unsigned int n) {
        // code here
        unsigned int ans=0;
        while(n>0)
        {
            ans=(ans<<1)|(n&1);
            n>>=1;
        }
        return ans;
    }
};