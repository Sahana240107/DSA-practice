/*Given an array arr[]. The array contains numbers ranging from 0 to k-1 where k is a positive integer.
 Find the maximum repeating number in this array. If there are two or more maximum repeating numbers, 
 return the element with the least value.

Examples:

Input: k = 3, arr[] = [2, 2, 1, 2]
Output: 2
Explanation: 2 is the most frequent element.
*/
// User function template for C++
class Solution {
  public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    int maxRepeating(int k, vector<int>& arr) {
        // code here
        unordered_map<int,int> freq;
        int maxi=0,freqx=0;
        for(int x:arr)
        {
            freq[x]++;
            if(freq[x]>maxi || (freq[x]==maxi && freqx>x))
            {
                maxi=freq[x];
                freqx=x;
            }
        }
        return freqx;
    }
};