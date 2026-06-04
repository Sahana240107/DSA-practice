/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy=ListNode(0,head);
        ListNode *temp=&dummy;
        while(temp->next!=NULL)
        {
            if(temp->next->val==val)
            {
                ListNode *toDelete=temp->next;
                temp->next=toDelete->next;
                delete toDelete;
            }
            else
            {
                temp=temp->next;
            }
        }
        return dummy.next;
    }
};

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                prev?prev->next=temp->next:head=temp->next;
            }
            else
                prev=temp;
            temp=temp->next;
        }
        return head;
    }
};