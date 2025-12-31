/*You are given an array, arr[]. Find the minimum index based distance between two distinct elements of the array, x and y. Return -1, if either x or y does not exist in the array.

Examples:

Input: arr[] = [1, 2, 3, 2], x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are two distances between x and y, which are 1 and 3 out of which the least is 1.
*/
class Solution {
  public:
    int minDist(vector<int>& arr, int x, int y) {
        int last=-1,ans=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==x || arr[i]==y)
            {
                if(last!=-1 && arr[i]!=arr[last])
                {
                    ans=min(ans,i-last);
                }
                last=i;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};