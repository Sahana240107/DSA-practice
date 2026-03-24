/*Given an integer array  . Calculate the sum for the elements of  between indices  and  inclusive where  .

NOTE: left,right follows zero based indexing.

Input Format

The first line contains an integer  which denotes the number of elements in the array nums.

The second line contains  space-separated integers, representing the elements of the array 

The third line contains two space-separated integers  and .

Constraints



Output Format

The output is a integer.

Sample Input 0

5
-10 -4 -4 4 -8
1 4
Sample Output 0

-12
Explanation 0

Fot the given array, Index: 0 1 2 3 4 Value: -10 -4 -4 4 -8

wkt left = 1, right = 4

Thus, result = nums[1] + nums[2] + nums[3] + nums[4] = (-4) + (-4) + 4 + (-8) = -12*/

vector<int> buildPrefix(vector<int>& nums, int n) {
    vector<int> prefix(n);
    prefix[0] = nums[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + nums[i];
    }

    return prefix;
}

int rangeSum(vector<int>& prefix, int l, int r) {
    if (l == 0)
        return prefix[r];
    return prefix[r] - prefix[l-1];
}