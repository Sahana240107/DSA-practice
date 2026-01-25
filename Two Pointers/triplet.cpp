/*Given an array arr of integers. First sort the array then find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [3, 4, 5]
Output: false
Explanation: No triplets satisfy the condition.*/

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        if(arr.size()<3)
            return false;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int k=n-1;k>=2;k--)
        {
            int key=arr[k],i=0,j=k-1;
            while(i<j)
            {
                long long sum=(long long)arr[i]+arr[j];
                if(sum==key)
                    return true;
                else if(sum<key)
                    i++;
                else
                    j--;
            }
        }
        return false;
    }
};