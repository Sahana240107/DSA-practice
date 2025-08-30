/*You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.*/
/*Input:
ab*c+ 
Output: 
((a*b)+c)*/
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(int i=0;i<exp.length();i++)
        {
            if(isalnum(exp[i]))
            {
                string s=string(1,exp[i]);
                st.push(s);
            }
            else
            {
                string s2=st.top();
                st.pop();
                string s1=st.top();
                st.pop();
                string str='('+s1+exp[i]+s2+')';
                st.push(str);
            }   
        }
        return st.top();
    }
};