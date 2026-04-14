/*Given a string S, check whether it can be converted into the string "hello" by deleting some characters from it.
Note : S can have both uppercase and lowercase letters.

Example 1:

Input:
S = "bbbbbxxhhelllllooudd"
Output: 1
Explanation: The string hello is marked
in bold: bbbbbxxhhelllllooudd

â€‹Example 2:

Input: 
S = "hlelo"
Output: 0
Explanation: It's impossible to convert
the given string into "hello".

*/

bool decode(string S) {
    // your code here
    string pat="hello";
    int i=0;
    for(int j=0;j<S.length();j++)
    {
        if(S[j]==pat[i])
            i++;
        if(i==5)
            return 1;
    }
    return i==5?1:0;
}