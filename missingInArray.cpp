/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). 
This array represents a permutation of the integers from 1 to n with one element missing. 
Your task is to identify and return the missing element.*/

/*Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.*/
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long int n=arr.size()+1,sum=0;
        long int expectedSum=n*(n+1)/2;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        return expectedSum-sum;//Total sum-actual sum will give missing number
    }
};
