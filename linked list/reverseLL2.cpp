/*92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
            return NULL;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* before=dummy;
        ListNode* curr=head;
        int pos=1;
        while(curr && pos<left)
        {
            pos++;
            before=curr;
            curr=curr->next;
        }
        ListNode* temp=curr;
        ListNode* prev=NULL;
        while(temp!=NULL && pos<=right)
        {
            pos++;
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        before->next=prev;
        curr->next=temp;
        return dummy->next;
    }
};