/*The Painter's Partition Problem-II
Difficulty: HardAccuracy: 27.52%Submissions: 187K+Points: 8
Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: A valid optimal partition is - 
Painter 1 → [10, 20, 30] → time = 60
Painter 2 → [40] → time = 40
Job will be complete at time = max(60, 40) = 60*/
class Solution {
    int maxElement(vector<int>& a)
    {
        int maxi=a[0];
        for(int i=1;i<a.size();i++)
        {
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
    int sumArr(vector<int>& a)
    {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum+=a[i];
        return sum;
    }
    int countPainter(int maxi,vector<int> a)
    {
        int painter=1,val=0;
        for(int i=0;i<a.size();i++)
        {
            if(val+a[i]<=maxi)
                val+=a[i];
            else
            {
                painter++;
                val=a[i];
            }
        }
        return painter;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        if(arr.size()<k)
            return -1;
        int low=maxElement(arr);
        int high=sumArr(arr);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(countPainter(mid,arr)>k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
        
    }
};