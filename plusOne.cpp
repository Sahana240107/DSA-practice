/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
 The digits are ordered from most significant to least significant in left-to-right order.
 The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/
/*Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4]*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int t;
        for(int i=digits.size()-1;i>=0;i--)//Looping from end
        {
            if(digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            else
            {
                digits[i]=0;//digit is 9
                if(i==0)
                {
                    digits.insert(digits.begin(),1);//dealing numbers like 9,99,999
                }
            }
        }
        return digits;
    }
};