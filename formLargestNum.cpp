/*Given an array arr[] of numbers from 0 to 9. Your task is to rearrange elements of the array such that after combining all the elements of the array, the number formed is maximum.

Examples:

Input: arr[] = [9, 0, 1, 3, 0]
Output: 93100
Explanation: Largest number is 93100 which can be formed from array digits.
*/
class Solution {
  public:
    string MaxNumber(vector<int>& arr) {
        // code here.
        sort(arr.begin(),arr.end(),greater<int>());
        string s;
        for(int c:arr)
        {
            s+=c+'0';
        }
        return s;
    }
};