/*Given an array, arr[]. Sort the array using bubble sort algorithm.*/
class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int t;
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=0;j<arr.size()-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    t=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=t;
                }
            }
        }
    }
};