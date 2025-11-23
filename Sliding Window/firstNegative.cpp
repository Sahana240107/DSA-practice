/*Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.
*/
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<arr.size();i++)
        {
            if(!dq.empty() && dq.front()<=i-k)//remove index outside window
                dq.pop_front();
            if(arr[i]<0)
                dq.push_back(i);//push negative index
            if(i>=k-1)
            {
                if(!dq.empty())
                    ans.push_back(arr[dq.front()]);
                else
                    ans.push_back(0);
            }
        }
        return ans;
    }
};