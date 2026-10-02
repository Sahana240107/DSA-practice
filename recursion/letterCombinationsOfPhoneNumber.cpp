/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 
Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].*/

//Recursion
class Solution {
    void helper(int ind,string cur,string letters[],string digits,vector<string>& ans)
    {
        int n=digits.size();
        if(ind==n)
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<letters[digits[ind]-'2'].size();i++)
        {
            helper(ind+1,cur+letters[digits[ind]-'2'][i],letters,digits,ans);   
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        string letters[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        helper(0,"",letters,digits,ans);
        return ans;
    }
};