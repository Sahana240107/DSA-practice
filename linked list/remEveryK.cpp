/*Given a singly linked list, your task is to remove every kth node from the linked list. 

Examples:

Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 2
Output: 1 -> 3 -> 5 -> 7

Explanation: After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.
Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10

Explanation: After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.*/

class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        if(head==NULL || k==0)
            return
        if(k==1)
            return NULL;
        int i=1;
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL)
        {
         if(i%k==0)
         {
             prev->next=temp->next;
         }
         else
         {
             prev=temp;
         }
         i++;
         temp=temp->next;
        }
        return head;
    }
};