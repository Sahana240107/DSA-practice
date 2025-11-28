/*You are given two integer numbers in the form of string, the base a and the index b. You have to find the last digit of ab.

Examples:

Input: a = "3", b = "10"
Output: 9
Explanation: 310 = 59049. Last digit is 9.
*/
class Solution {
  public:
    int getLastDigit(string a, string b) {
        // code here
        if(b=="0")
            return 1;
        int last=a.back()-'0';
        vector<vector<int>> cycles = {
            {0},           // 0
            {1},           // 1
            {2,4,8,6},     // 2
            {3,9,7,1},     // 3
            {4,6},         // 4
            {5},           // 5
            {6},           // 6
            {7,9,3,1},     // 7
            {8,4,2,6},     // 8
            {9,1}          // 9
        };
        vector<int> cycle=cycles[last];
        int len=cycle.size();
        int mod=0;
        for(char c:b)
        {
            mod=(mod*10+(c-'0'))%len;
        }
        if(mod==0)
            mod=len;
        return cycle[mod-1];
    }
};