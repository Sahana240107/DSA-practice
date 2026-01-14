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

//To handle negative numbers too
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : arr) {
            // largest two
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }

            // smallest two
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }

        return max(max1 * max2, min1 * min2);
    }
};
