/*You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k==0)
        {
            vector<int> ans(n,0);
            return ans;
        }
        if(k>0)
        {
            vector<int> ans;
            int sum;
            for(int i=0;i<n;i++)
            {
                sum=0;
                for(int j=1;j<=k;j++)
                {
                    int ind=(i+j)%n;
                    sum+=code[ind];
                }
                ans.push_back(sum);
            }
            return ans;
        }
        else
        {
        vector<int> ans;
           int sum;
           k=-k;
            for(int i=n-1;i>=0;i--)
            {
                sum=0;
                for(int j=1;j<=k;j++)
                {
                    int ind=(i-j+n)%n;
                    sum+=code[ind];
                }
                ans.push_back(sum);
            }
            reverse(ans.begin(),ans.end());
            return ans; 
        }
    }
};