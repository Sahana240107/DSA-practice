/*You are given an array of integers arr[]. 
Your task is to reverse the given array.
Note: Modify the array in place.*/
/*Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]*/
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int i=0,j=arr.size()-1,temp;
        while(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
};