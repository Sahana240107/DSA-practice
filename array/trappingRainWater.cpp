/*42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suf(n);
        suf[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=max(suf[i+1],height[i]);
        }
        int water=0;
        int leftMax=height[0];
        for(int i=1;i<n-1;i++)
        {
            if(leftMax>height[i] && suf[i+1]>height[i])
                water+=min(leftMax,suf[i+1])-height[i];
            leftMax=max(leftMax,height[i]);
        }
        return water;
    }
};