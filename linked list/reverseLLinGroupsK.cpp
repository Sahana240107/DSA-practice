/*25. Reverse Nodes in k-Group
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/
class Solution {
    ListNode* kthNode(ListNode* cur,int k)
    {
        k--;
        while(cur && k>0)
        {
            cur=cur->next;
            k--;
        }
        return cur;
    }
    void reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* cur=head;
        while(cur)
        {
            ListNode* front=cur->next;
            cur->next=prev;
            prev=cur;
            cur=front;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp)
       {
            ListNode* kth=kthNode(temp,k);
            if(!kth)
            {
                if(prev)
                    prev->next=temp;
                break;
            }
            ListNode* nextNode=kth->next;
            kth->next=NULL;
            reverse(temp);
            if(temp==head)
                head=kth;
            else
                prev->next=kth;
            prev=temp;
            temp=nextNode;
       } 
       return head;
    }
};