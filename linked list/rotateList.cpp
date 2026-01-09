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
/*You are given the head of a singly linked list, you have to left rotate the linked list k times. Return the head of the modified linked list.

Examples:

Input: k = 4,
   
Output: 50 -> 10 -> 20 -> 30 -> 40
Explanation:
Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
Rotate 4: 50 -> 10 -> 20 -> 30 -> 40
   
*/
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        if(!head||!head->next||k==0)
            return head;
        int len=1;
        Node* last=head;
        while(last->next)
        {
            last=last->next;
            len++;
        }
        k=k%len;
        if(k==0)
            return head;
        last->next=head;
        Node* newTail=head;
        for(int i=1;i<k;i++)
        {
            newTail=newTail->next;
        }
        Node* newHead=newTail->next;
        newTail->next=NULL;
        return newHead;
    }
};