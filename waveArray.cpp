/*Given an sorted array arr[] of integers. Sort the array into a wave-like array(In Place). 
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5] ..... and so on. 
If there are multiple solutions, find the lexicographically smallest one.
Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.*/
class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        int temp;
        for(int i=0;i<arr.size()-1;i++)
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            i++;//swap alternatively
        }
    }
};