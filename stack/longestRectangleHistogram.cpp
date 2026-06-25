/*84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/
class Solution {
    vector<int> findnse(vector<int>& heights)
    {
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int>& heights)
    {
        int n=heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse=findnse(heights);
        vector<int> pse=findpse(heights);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int h=(nse[i]-pse[i]-1);
            maxi=max(maxi,h*heights[i]);
        }   
        return maxi;
    }
};

/OPTIMAL
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && (i==n||heights[st.top()]>heights[i]))
            {
                int h=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int width=nse-pse-1;
                maxi=max(maxi,width*h);
            }
            st.push(i);
        }
        
    }
};