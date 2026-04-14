/*Given an integer array of which both the first halve and second halve are sorted. The task is to merge these two sorted halves of the array into a single sorted array.
Note: The two halves can be of arbitrary sizes (i.e. if first halve of size k then the second halve is of size N-k where 0<=k<=N).

Example 1:

Input:
N = 6
arr[] = {2 3 8 -1 7 10}
Output: -1 2 3 7 8 10 
Explanation: {2 3 8} and {-1 7 10} are sorted 
in the original array. The overall sorted 
version is {-1 2 3 7 8 10}*/

class Solution {
  public:
    void sortHalves(int arr[], int n) {
        // your code here
        int k=0;
        for(k=0;k<n;k++)
        {
            if(arr[k]>arr[k+1])
                break;
        }
        int i=0,j=k+1;
        vector<int> temp;
        while(i<=k && j<n)
        {
            if(arr[i]<=arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i<=k)
            temp.push_back(arr[i++]);
        while(j<n)
            temp.push_back(arr[j++]);
        for(int i=0;i<n;i++)
            arr[i]=temp[i];
    }
};