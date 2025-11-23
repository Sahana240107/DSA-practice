/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 */
 /*Input: s = "([])"
Output: true*/
class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char c:str)
        {
            if(c=='[' || c=='{' || c=='(')
            {
                s.push(c);
            }
            else
            {
                if(s.empty())
                {
                    return false;//no open parentheses
                }
                char top=s.top();
                if(c==']' && top=='[' || c=='}' && top=='{' || c==')' && top=='(')//checking for match
                {
                    s.pop();//if match pop
                }
                else
                {
                    return false;//no matching close parentheses
                }
            }
        }
        return s.empty();
    }
};