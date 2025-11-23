/*You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
Return the binary representation of date.
Example 1:
Input: date = "2080-02-29"
Output: "100000100000-10-11101"*/
class Solution {
public:
    string toBinary(int n)
    {
        string s="";
        if(n==0)
        {
            s='0';
        }
        while(n>0)
        {
            s=char(n%2+'0')+s;
            n/=2;
        }
        return s;
        
    }
    string convertDateToBinary(string date) {
        string datestr,monthstr,yearstr,binary;
        int day,month,year;
        stringstream ss(date);//split input str
        getline(ss,yearstr,'-');
        getline(ss,monthstr,'-');
        getline(ss,datestr,'-');
        day=stoi(datestr);//convert to int
        month=stoi(monthstr);
        year=stoi(yearstr);
        datestr=toBinary(day);
        monthstr=toBinary(month);
        yearstr=toBinary(year);
        binary=yearstr+"-"+monthstr+"-"+datestr;
        return binary;

    }
};