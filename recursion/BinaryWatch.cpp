/*401. Binary Watch
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

For example, the below binary watch reads "4:51".


Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".
 

Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
Example 2:

Input: turnedOn = 9
Output: []
 

Constraints:

0 <= turnedOn <= 10*/

class Solution {
    vector<int> hr={1,2,4,8};
    vector<int> min={1,2,4,8,16,32};
    void helper(int ind,int count,int hrs,int mins,int& turnedOn,vector<string>& ans)
    {
        if(count==turnedOn)
        {
            if(hrs<12 && mins<60)
            {
                string time=to_string(hrs)+":";
                if(mins<10)
                    time+="0";
                time+=to_string(mins);
                ans.push_back(time);
                return;
            }
        }
        if(ind==10)
            return;
        if(10-ind<turnedOn-count)
            return;
        if(ind<4)
            helper(ind+1,count+1,hrs+hr[ind],mins,turnedOn,ans);
        else
            helper(ind+1,count+1,hrs,mins+min[ind-4],turnedOn,ans);
        helper(ind+1,count,hrs,mins,turnedOn,ans);
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        helper(0,0,0,0,turnedOn,ans);
        return ans;
    }
};