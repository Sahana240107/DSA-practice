/*Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 780K+Points: 4
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.*/
class Solution {
    int merge(int low,int mid,int high,vector<int>& arr)
    {
        int temp[high-low+1];
        int count=0;
        int i=low,j=mid+1,k=0;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
                temp[k++]=arr[i++];
            else
            {
                count+=mid-i+1;
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=high)
        {
            temp[k++]=arr[j++];
        }
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        return count;
    }
    int mergesort(int low,int high,vector<int>& arr)
    {
        if(low>=high)
            return 0;
        int count=0;
        int mid=low+(high-low)/2;
        count+=mergesort(low,mid,arr);
        count+=mergesort(mid+1,high,arr);
        count+=merge(low,mid,high,arr);
        return count;
    }
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergesort(0,arr.size()-1,arr);
    }
};