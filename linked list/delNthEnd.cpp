/*Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first=head;
        for(int i=1;i<=n;i++)
            first=first->next;
        if(first==NULL)//if n==length that is to delete head
        {
            head=head->next;
            return head;
        }
        ListNode* second=head;
        while(first->next!=NULL)//to get previous node of nth node from end
        {
            first=first->next;
            second=second->next;
        }
        ListNode* toDelete=second->next;
        second->next=toDelete->next;
        delete toDelete;
        return head;
    }
};