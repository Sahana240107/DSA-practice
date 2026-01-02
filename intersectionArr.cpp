/*Given two unsorted integer arrays a[] and b[] each consisting of distinct elements, the task is to return the count of elements in the intersection (or common elements) of the two arrays.

Intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 

Examples:

Input: a[] = [89, 24, 75, 11, 23], b[] = [89, 2, 4]
Output: 1
Explanation: 89 is the only element in the intersection of two arrays.
*/
class Solution {
  public:
    int intersectSize(vector<int> &a, vector<int> &b) {
        // code  here
        unordered_set<int> s;
        for(int x:a)
        {
           s.insert(x);
        }
        int count=0;
        for(int x:b)
        {
            if(s.find(x)!=s.end())
                count++;
        }
        return count;
    }
};