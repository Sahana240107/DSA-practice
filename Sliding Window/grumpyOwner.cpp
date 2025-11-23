/*There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.

During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.

The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.

Return the maximum number of customers that can be satisfied throughout the day.

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3

Output: 16

Explanation:

The bookstore owner keeps themselves not grumpy for the last 3 minutes.

The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        long sumCus=0,maxCus=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(i<minutes)//trick in initial window
                sumCus+=customers[i];
            else if(grumpy[i]==0)//always satisfied customers(base case)
                sumCus+=customers[i];
        }
        maxCus=sumCus;
        for(int i=minutes;i<grumpy.size();i++)
        {
            if(grumpy[i-minutes]!=0)//remove unsatisfied customers outside window
                sumCus-=customers[i-minutes];
            if(grumpy[i]!=0)//add unsatisfied customers in the window
                sumCus+=customers[i];
            maxCus=max(maxCus,sumCus);
        }
        return maxCus;
    }
};