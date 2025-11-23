/*Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps,
 where d is a positive integer. Do the mentioned change in the array in place.
Note: Consider the array as circular.*/
/*Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.*/
class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n=arr.size();
        d=d%n;
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
    }
};