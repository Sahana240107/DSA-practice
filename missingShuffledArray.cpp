/*Given an array arr1. The contents of arr are copied into another array arr2 and numbers are shuffled.
 Also, one element is removed from arr2. The task is to find the missing element.*/
/*Input: arr1[] = [4, 8, 1, 3, 7] and arr2[] = [7, 4, 3, 1]
Output: 8
Explanation: 8 is the only element missing from arr2.*/


class Solution {
  public:
    int findMissing(vector<int>& arr1, vector<int>& arr2) {
        int xor1=0,xor2=0,i;
        for(i=0;i<arr2.size();i++)
        {
            xor1=xor1^arr1[i];
            xor2=xor2^arr2[i];
        }
        xor1=xor1^arr1[i];//arr1 has one more element
        return xor1^xor2;
    }
};