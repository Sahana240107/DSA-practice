/*Given an integer array  of size , sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between  and  (inclusive). Determine the number of rotations performed on the array.

Input Format

The first line contains an integer , the number of elements of the array.

The second line contains  space separated integers, the elements of the array.

A single integer denoting the number of times the array has been rotated.

Sample Input 0

8
4 5 6 7 0 1 2 3
Sample Output 0

4
Explanation 0

The original array should be . So, we can notice that the array has been rotated 4 times.

Sample Input 1

5
3 4 5 1 2
Sample Output 1

3
Explanation 1

The original array should be . So, we can notice that the array has been rotated 3 times.*/

int numberOfRotations(vector<int> nums, int n) {
    int left=0,right=n-1;
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]>nums[right])
            left=mid+1;
        else
            right=mid;
    }
    return left;
}