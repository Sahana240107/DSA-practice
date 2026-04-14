/*Given a string s, extract all the integers from s.

Example 1:

Input:
s = "1: Prakhar Agrawal, 2: Manish Kumar Rai, 
     3: Rishabh Gupta56"
Output: 1 2 3 56
Explanation: 
1, 2, 3, 56 are the integers present in s.
Example 2:

Input:
s = "geeksforgeeks"
Output: No Integers
Explanation: 
No integers present in the string.*/
vector<string> extractIntegerWords(string s) {
    // code here
    vector<string> ans;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            string num=string(1,s[i]);
            while(s[i+1]>='0' && s[i+1]<='9')
            {
                num+=s[i+1];
                i++;
            }
            ans.push_back(num);
        }
    }
    return ans;
}