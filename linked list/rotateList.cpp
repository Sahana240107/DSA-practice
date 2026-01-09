/*Given the head of a linked list, rotate the list to the right by k places.
Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0)
            return head;
        ListNode* last=head;
        int len=1;
        while(last->next)
        {
            last=last->next;
            len++;
        }
        k=k%len;
        if(k==0)
            return head;
        last->next=head;
        ListNode* newTail=head;
        int step=len-k;
        for(int i=1;i<step;i++)
        {
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        newTail->next=NULL;
        return newHead;
    }
};