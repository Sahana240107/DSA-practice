/*493. Reverse Pairs
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1*/

class Solution {
    void merge(int low,int mid,int high,vector<int>& arr)
    {
        int temp[high-low+1];
        int i=low,j=mid+1,k=0;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j])
                temp[k++]=arr[i++];
            else
            {
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
    }
    int countPairs(int low,int mid,int high,vector<int>& arr)
    {
        int count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && arr[i]>2LL*arr[j])   
                j++;
            count+=(j-mid-1);
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
        count+=countPairs(low,mid,high,arr);
        merge(low,mid,high,arr);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};