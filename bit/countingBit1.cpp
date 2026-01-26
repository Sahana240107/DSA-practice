/*Given an integer n, count the number of 1's in the binary representation of every number in the range [0, n].

Return an array output where output[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 4

Output: [0,1,1,2,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100*/
//Brian Kernighan method
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int x = i;        // temp variable
            int count = 0;
            while (x) {
                x = x & (x - 1);
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
