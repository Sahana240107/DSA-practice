/*Problem Statement: Given an array nums and an integer k.
Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k*/
class Solution {
    bool subSum(int i,vector<int> a,int k,int sum)
    {
        if(sum>k)
            return false;
        if(i==a.size())
        {
            if(sum==k)
                return true;
            else
                return false;
        }
        sum+=a[i];
        if(subSum(i+1,a,k,sum))
            return true;
        sum-=a[i];
        if(subSum(i+1,a,k,sum))
            return true;
        return false;
    }
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        return subSum(0,arr,k,0);
    }
};