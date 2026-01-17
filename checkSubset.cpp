/*Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

Examples:

Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: true
Explanation: b[] is a subset of a[]
Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
Output: true
Explanation: b[] is a subset of a[]
Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
Output: false
Explanation: b[] is not a subset of a[]
*/

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int> frq;
        for(int x:b)
        {
            frq[x]++;
        }
        for(int x:a)
        {
            if(frq.count(x))
            {
                frq[x]--;
                if(frq[x]==0)
                    frq.erase(x);
            }
            if(frq.empty())
                return true;
        }
        return frq.empty();
        
    }
};