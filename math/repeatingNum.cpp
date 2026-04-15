/*Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Your task is to find the repetitive element.

Note: It is guaranteed that there is a repeating element present in the array.

Examples:

Input: arr[] = [1, 3, 2, 3, 4]
Output: 3 
Explanation: The number 3 is the only repeating element.
Input: arr[] = [1, 5, 1, 2, 3, 4]
Output: 1  
Explanation: The number 1 is the only repeating element.
*/
// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int xor1=0;
        for(int i=0;i<arr.size();i++)
        {
            xor1=xor1^arr[i]^i;
        }
        return xor1;
    }
};