/*You are given the head of a singly linked list and an integer x. Delete the xth node (1-based indexing) from the singly linked list.

Examples:

Input: x = 1,
    
Output: 2 -> 3 -> 1 -> 7

Input: x = 5,
    
Output: 2 -> 3 -> 4 -> 5
    */
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        if(head==NULL)
            return NULL;
        if(x==1)
        {
            Node* toDelete=head;
            head=head->next;
            delete toDelete;
            return head;
        }
        Node* temp=head;
        int i=1;
        while(temp->next!=NULL && i<x-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp->next==NULL)
        {
            return head;
        }
        Node* toDelete=temp->next;
        temp->next=toDelete->next;
        delete toDelete;
        return head;
    }
};