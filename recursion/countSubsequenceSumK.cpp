/*Problem Statement: Given an array nums and an integer k.
Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k*/
class Solution {
    int subSum(int i,vector<int> a,int k,int sum)
    {
        if(sum>k)
            return 0;
        if(i==a.size())
        {
            return sum==k?1:0;
        }
        sum+=a[i];
        int ls=subSum(i+1,a,k,sum);
        sum-=a[i];
        int rs=subSum(i+1,a,k,sum);
        return ls+rs;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        return subSum(0,arr,target,0);
    }
};