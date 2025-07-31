/*Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.
Note: In the case of a single vertical line it will not be able to hold water.
Examples:
Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: 5 and 3 are 2 distance apart. So the size of the base is 2. Height of container = min(5, 3) = 3. So, total area to hold water = 3 * 2 = 6.*/
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        long max_area=0,area=0;
        int i=0,j=arr.size()-1;
        while(i!=j)
        {
            area=min(arr[i],arr[j])*(j-i);
            max_area=max(max_area,area);
            (arr[i]<arr[j])?i++:j--;
        }
        return max_area;
    }
};