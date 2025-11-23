/*You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.
Example 1:
Input: 
*-A/BC-/AKL
Output: 
((A-(B/C))*((A/K)-L))*/

class Solution {
  public:
    string preToInfix(string pre_exp) {
        int i=pre_exp.length()-1;
        stack<string> st;
        string res="";
        while(i>=0)//reverse iteration
        {
            if(isalnum(pre_exp[i]))
            {
                st.push(string(1,pre_exp[i]));
            }
            else
            {
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string con="("+a+pre_exp[i]+b+")";
                st.push(con);
            }
            i--;
        }
        return st.top();
    }
};