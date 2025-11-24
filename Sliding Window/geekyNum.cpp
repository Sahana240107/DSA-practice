/*Geek just learned about Fibonacci numbers.

The Fibonacci Sequence is the series of numbers: 0, 1, 1, 2, 3, 5, 8, 13, ...
where the next number is found by adding up the two numbers before it.

He defines a new series called Geeky numbers. Here the next number is the sum of the K preceding numbers.
You are given an array of size K, GeekNum[ ], where the ith element of the array represents the ith Geeky number. Return its Nth term.

Input:
N = 5, K = 3
GeekNum[] = {0, 1, 2}
Output: 
6
Explanation: 
Terms are 0, 1, 2, 3, 6.
So the 5th term is 6
*/
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        long long sum=0;
        vector<long long> ans;
        for(int i=0;i<K;i++)
        {
            ans.push_back(GeekNum[i]);
            sum+=GeekNum[i];
        }
        ans.push_back(sum);
        for(int i=K;i<N;i++)
        {
            sum+=ans[i]-ans[i-K];
            ans.push_back(sum);
        }
        return ans[N-1];
    }
};