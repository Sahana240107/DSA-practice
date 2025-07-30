/*Given an array arr[] of size n, containing elements from the range 1 to n, 
and each element appears at most twice,return an array of all the integers that appears twice.
Note: You can return the elements in any order but the driver code will print them in sorted order.
Examples:
Input: arr[] = [2, 3, 1, 2, 3]
Output: [2, 3] 
Explanation: 2 and 3 occur more than once in the given array.*/
class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> res;       
        for(int i=0;i<arr.size();i++)
        {
            int j=abs(arr[i])-1;
            if(arr[j]<0)//already visited
            {
                res.push_back(j+1);
            }
            else
            {
                arr[j]=-arr[j];//mark as visited
            }
        }
        return res;
    }
};