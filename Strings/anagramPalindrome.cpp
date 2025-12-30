/*Given a string S, Check if characters of the given string can be rearranged to form a palindrome.
Note: You have to return 1 if it is possible to convert the given string into palindrome else return 0. 

Example 1:

Input:
S = "geeksogeeks"
Output: Yes
Explanation: The string can be converted
into a palindrome: geeksoskeeg

Example 2:

Input: 
S = "geeksforgeeks"
Output: No
Explanation: The given string can't be
converted into a palindrome.
*/
int isPossible(string S) {
    // your code here
    unordered_map<char,int> freq;
    for(char c:S)
    {
        freq[c]++;
    }
    int odd=0;
    for(auto it:freq)
    {
        if(it.second%2!=0)
            odd++;
    }
    return (odd<=1);
}