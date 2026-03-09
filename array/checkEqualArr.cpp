/*Given two arrays a[] and b[] of equal size, the task is to find whether the elements in the arrays are equal.
Two arrays are said to be equal if both contain the same set of elements, arrangements (or permutations) of elements may be different though.
Note: If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.

Examples:

Input: a[] = [1, 2, 5, 4, 0], b[] = [2, 4, 5, 0, 1]
Output: true
Explanation: Both the array can be rearranged to [0,1,2,4,5]*/
class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        if(a.size()!=b.size())
        {
            return false;
        }
        unordered_map<int,int> freq;
        for(int i:a)
        {
            freq[i]++;
        }
        for(int i:b)
        {
            freq[i]--;
        }
        for(auto i:freq)
        {
            if(i.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};