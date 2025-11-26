/*Given a mathematical equation that contains only numbers and +, -, *, /. Print the equation in reverse, such that the equation is reversed, but the numbers remain the same.
It is guaranteed that the given equation is valid, and there are no leading zeros.

Example 1:

Input:
S = "20-3+5*2"
Output: 2*5+3-20
Explanation: The equation is reversed with
numbers remaining the same.*/
class Solution {
  public:
    string reverseEqn(string s) {
        // code here.
        int n=s.length();
        stack<string> st;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                string num="";
                while(i<n && isdigit(s[i]))
                {
                    num+=s[i];
                    i++;
                }
                st.push(num);
                i--;
            }
            else
                st.push(string(1,s[i]));
        }
        string rev;
        while(!st.empty())
        {
            rev+=st.top();
            st.pop();
        }
        return rev;
    }
};