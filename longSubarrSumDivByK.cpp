/*Given an array arr[] and a positive integer k, find the length of the longest subarray with the sum of the elements divisible by k.
Note: If there is no subarray with sum divisible by k, then return 0.

Examples :

Input: arr[] = [2, 7, 6, 1, 4, 5], k = 3
Output: 4
Explanation: The subarray [7, 6, 1, 4] has sum = 18, which is divisible by 3.
*/
// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        unordered_map<int,int> mp;
        int rem=0,maxlen=0;
        for(int i=0;i<arr.size();i++)
        {
               rem+=arr[i];
               rem=((rem%k)+k)%k;
               if(rem==0)
                    maxlen=i+1;
                if(mp.find(rem)!=mp.end())
                    maxlen=max(maxlen,i-mp[rem]);
                if(mp.find(rem)==mp.end())
                    mp[rem]=i;
        }
        return maxlen;
    }
};