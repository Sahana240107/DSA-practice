/*Given an array arr of non-negative integers, return the maximum product of two numbers possible.

Example:

Input: arr[] = [1, 4, 3, 6, 7, 0] 
Output: 42
Explanation: 6 and 7 have the maximum product.*/

class Solution {
  public:

    int maxProduct(vector<int>& arr) {
        int maxi=INT_MIN,second=INT_MIN;
        for(int x:arr)
        {
            if(x>maxi)
            {
                second=maxi;
                maxi=x;
            }
            else if(x>second)
                second=x;
        }
        return maxi*second;
    }
};