/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasin
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.*/
/*Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].*/
//Using two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1,sum=0;
        while(i<j)
        {
            sum=numbers[i]+numbers[j];
            if(sum==target)
                return {i+1,j+1};
            else if(sum<target)
                i++;
            else
                j--;         
        }
        return {};
    }
};