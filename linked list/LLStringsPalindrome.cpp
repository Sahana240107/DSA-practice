/*Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

Example:

Input:

Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.
*/
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string st;
        Node* temp=head;
        while(temp!=NULL)
        {
            st+=temp->data;
            temp=temp->next;
        }
        int n=st.length();
        int i=0,j=n-1;
        while(i<=j)
        {
            if(st[i]!=st[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};