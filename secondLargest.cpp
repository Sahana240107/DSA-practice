/*Given an array of positive integers arr[], return the second largest element from the array. 
If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.*/
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        if(arr.size()<2)
        {
            return -1;
        }
        int max=INT_MIN,second=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>max)
            {
                second=max;
                max=arr[i];
            }
            if(arr[i]>second && arr[i]<max)
            {
                second=arr[i];
            }
        }
        return (second==INT_MIN)?-1:second;
    }
};