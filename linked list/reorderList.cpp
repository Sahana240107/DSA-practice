/*143. Reorder List
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        while(temp)
        {
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        ListNode* first=head;
        ListNode* second=prev;
        while(second)
        {
            ListNode* t1=first->next;
            ListNode* t2=second->next;
            first->next=second;
            second->next=t1;
            first=t1;
            second=t2;
        }
    }
};
