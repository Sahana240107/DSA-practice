/*Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a ≤ b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.
Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 5), (2, 7) and (4, 7) both are closest to 10, but absolute difference of (4, 5) is 1, (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 
*/

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        if(arr.size() < 2)
            return {};

        sort(arr.begin(), arr.end());

        int i = 0, j = arr.size() - 1;

        int closeDif = INT_MAX;
        vector<int> close;

        while(i < j) {
            int sum = arr[i] + arr[j];
            int diff = abs(target - sum);

            if(diff < closeDif) {
                closeDif = diff;
                close = {arr[i], arr[j]};
            }
            else if(diff == closeDif) {
                // max absolute difference
                if((arr[j] - arr[i]) > (close[1] - close[0])) {
                    close = {arr[i], arr[j]};
                }
            }
            if(sum < target)
                i++;
            else
                j--;
        }

        return close;
    }
};