/*Given a sorted array arr[]. Find the element that appears only once in the array. 
All other elements appear exactly twice. */
/*Input: arr[] = [1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65]
Output: 4
Explanation: 4 is the only element that appears exactly once.*/
class Solution {
  public:
    int single(vector<int>& arr) {
        int xor1=0;
        for(int i=0;i<arr.size();i++)
        {
            xor1=xor1^arr[i];//a^a=0
        }
        return xor1;
    }
};