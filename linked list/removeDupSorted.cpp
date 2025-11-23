/*Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:

Input: head = [1,1,2]
Output: [1,2]*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(prev && prev->val==temp->val)
            {
                prev->next=temp->next;
            }
            else//move prev only when it is not a duplicate
                prev=temp;
            temp=temp->next;
        }
        return head;
    }
};