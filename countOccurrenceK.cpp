/*Given an array arr[]. Your task is to return an integer denoting the total number of times digit k appears in the array.
Examples:
Input: k=1, arr[] = [11, 12, 13, 14, 15]
Output: 6 
Explanation: Here, digit 1 appears in the whole array 6 times.*/
class Solution {
  public:
    int num(int k, vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            while(arr[i]>0)
            {
                if(arr[i]%10==k)
                {
                    count++;
                }
                arr[i]/=10;
            }
        }
        return count;
    }
};