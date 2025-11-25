/*Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.*/
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int> br;
        int open=0;
        stack<pair<char,int>> st;
        for(char c:str)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                st.push({c,++open});
                br.push_back(open);
            }
            else if(c==')' || c=='}' || c==']')
            {
                if(!st.empty())
                {
                    if(c==')' && st.top().first=='(' || c=='}' && st.top().first=='{' || c==']' && st.top().first=='[')
                    {
                        br.push_back(st.top().second);
                        st.pop();
                    }
                }
            }
        }
        return br;
    }
};