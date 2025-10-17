/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 */
 class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
            slow=slow->next; //remove middle for odd length
        ListNode* temp=slow;
        while(temp!=NULL)
        {
            if(temp->val!=st.top())
                return false;
            st.pop();
            temp=temp->next;
        }
        return true;
    }

