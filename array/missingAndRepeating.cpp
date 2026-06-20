/*Missing And Repeating
Difficulty: EasyAccuracy: 24.83%Submissions: 710K+Points: 2Average Time: 30m
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int mis=-1,dup=-1;
        for(int i=0;i<arr.size();i++)
        {
            int ind=abs(arr[i])-1;
            if(arr[ind]>0)  
                arr[ind]=-arr[ind];
            else
                dup=ind+1;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>0)
                mis=i+1;
        }
        return {dup,mis};
    }
};